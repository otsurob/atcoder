#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(a,i,n) for(ll i=(a);i<(n);i++)
#define rrep(i, n) for(ll i=(n-1);i>=0;i--)
#define rrep2(a, i, n) for(ll i=(n-1);i>=a;i--)
#define cinv(v,n) for(ll i=0;i<(n);i++)cin>>v[i];
#define coutv(v,n) for(ll i=0;i<(n);i++)cout<<v[i]<<' ';
#define codl() cout<<endl;
#define couty() cout<<"Yes"<<endl;
#define coutn() cout<<"No"<<endl;
#define decout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define wow() cout<<"wow"<<endl;
#define coc(a) cout<<a<<endl;;
#define coc2(a, b) cout<<a<<" "<<b<<endl;
#define coc3(a, b, c) cout<<a<<" "<<b<<" "<<c<<endl;
#define coc4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
#define inf 999999999999999999
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }

// ラジアンを度に変換する関数
double toDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

double toDegreesForSort(int midx, int midy, int px, int py){
    double nodea=5*5;
    double nodeb=(px-midx)*(px-midx)+(py-midy)*(py-midy);
    double nodeab=(px-midx+5)*(px-midx+5)+(py-midy)*(py-midy);
    double cosa=(nodea+nodeb-nodeab)/(2*sqrt(nodea)*sqrt(nodeb));
    double radians = acos(cosa);
    double degrees = toDegrees(radians);
    if(py>=midy){
        return degrees;
    }else{
        return 360-degrees;
    }
}

int main(){
    int n;
    cin>>n;
    int ax, ay, bx, by;
    cin>>ax>>ay>>bx>>by;
    int theta;
    cin>>theta;
    vector<pair<double, double>> p(n);
    int ans=0;
    rep(i, n){
        cin>>p[i].first>>p[i].second;
    }
    if(theta==360){
        cout<<n<<endl;
        return 0;
    }
    vector<vector<double>> sorteda, sortedb;
    rep(i, n){
        sorteda.push_back({toDegreesForSort(ax, ay, p[i].first, p[i].second), p[i].first, p[i].second, (double)i});
        sorteda.push_back({toDegreesForSort(bx, by, p[i].first, p[i].second), p[i].first, p[i].second, (double)i});
    }
    sort(sorteda.begin(), sorteda.end());
    sort(sortedb.begin(), sortedb.end());
    rep(i, n-1){
        rep2(i+1, j, n){
            double nodea=(sorteda[i][1]-ax)*(sorteda[i][1]-ax)+(sorteda[i][2]-ay)*(sorteda[i][2]-ay);
            double nodeb=(sorteda[j][1]-ax)*(sorteda[j][1]-ax)+(sorteda[j][2]-ay)*(sorteda[j][2]-ay);
            double nodeab=(sorteda[i][1]-sorteda[j][1])*(sorteda[i][1]-sorteda[j][1])+(sorteda[i][2]-sorteda[j][1])*(sorteda[i][2]-sorteda[j][1]);
            double cosa=(nodea+nodeb-nodeab)/(2*sqrt(nodea)*sqrt(nodeb));
            double radians = acos(cosa);
            double degrees = toDegrees(radians);

            vector<double> tv(2);
            tv[0]=degrees, tv[1]=360-degrees;

            rep(l, 2){
                double d = tv[l];
                if(d>theta)continue;
                vector<bool> islighted(n, false);
                // 2直線の間に頂点があるか判定
                rep(k, n){
                    if(l==0){
                        if(sorteda[k][0]>=sorteda[i][0] and sorteda[k][0]<=sorteda[j][0]){
                            islighted[sorteda[k][3]]=true;
                        }
                    }else{
                        if(sorteda[k][0]>=sorteda[j][0] or sorteda[k][0]<=sorteda[i][0]){
                            islighted[sorteda[k][3]]=true;
                        }
                    }
                }
                double dd=theta-d;
                // 装置Bの光の片端が植物kを通る
                rep(k, n){
                    vector<bool> islighted2(n, false);
                    rep(w, n){
                        if(sortedb[w][0]>=sortedb[k][0] and sortedb[w][0]<=sortedb[k][0]+dd){
                            islighted2[sortedb[w][3]]=true;
                        }
                    }
                    int cnt=0;
                    rep(w, n){
                        if(islighted[w] or islighted2[w])cnt++;
                    }
                    ans=max(ans, cnt);
                }
            }
        }
    }
    cout<<ans<<endl;
}