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

class flight{
    private:
        int depid;
        int arrid;
        int dept;
        int arrt;

    public:
        void set_flight(int did, int aid, int dt, int at){
            depid=did;
            arrid=aid;
            dept=dt;
            arrt=at;
        }
        vector<int> get_flight(){
            return {depid, arrid, dept, arrt};
        }
};

class user_reservation{
    private:
        int r_id;
        int price;
        int date;
        int flight_name;
        int seat_id;
        int depflight;
        int dept;
        int arrflight;
        int arrt;
};


int main(){
    int n;
    cin>>n;
    map<int, bool> flight_id_check;
    map<int, flight> finfo;
    map<int, vector<pair<int, int>>> seat_p;
    map<int, vector<string>> flight_seat;
    map<int, vector<int>> flight_seat_price;
    map<pair<int, string>, vector<string>> seat_info;
    int reservation_id=1;
    rep(i, n){
        int a, b, c, d, e, s, x, y;
        cin>>a>>b>>c>>d>>e;
        flight f;
        f.set_flight(b, c, d, e);
        finfo[a]=f;
        flight_id_check[a]=true;
        cin>>s;
        string seat_column="";
        vector<int> price_tmp;
        rep(j, s){
            cin>>x>>y;
            seat_p[a].push_back(pair<int, int>(x, y));
            rep(k, x){
                seat_column.push_back((j+1)+'0');
                price_tmp[k]=y;
            }
        }
        vector<string> seat_tmp(4);
        rep(j, 4)seat_tmp[j]=seat_column;
        flight_seat[a]=seat_tmp;
        flight_seat_price[a]=price_tmp;
    }
    int m;
    cin>>m;
    while(m--){
        string query;
        cin>>query;
        if(query=="reserve:"){
            string r_date, seat_id, flight_date;
            int user_id, flight_id;
            cin>>r_date>>user_id>>flight_date>>flight_id>>seat_id;
            int seat_id_column=seat_id[0]-'0', seat_id_row=seat_id[1]-'A';
            if(!flight_id_check[flight_id]){
                cout<<"reserve: flight not found"<<endl;
                continue;
            }
            if(){
                cout<<"reserve: too late"<<endl;
                continue;
            }
            if(seat_info.count(pair<int, string>(flight_id, flight_date))==0)seat_info[pair<int, string>(flight_id, flight_date)]=flight_seat[flight_id];
            if(seat_info[pair<int, string>(flight_id, flight_date)][seat_id_row][seat_id_column]=='X'){
                cout<<"reserve: already reserved"<<endl;;
                continue;
            }
            seat_info[pair<int, string>(flight_id, flight_date)][seat_id_row][seat_id_column]='X';
            // userの予約履歴に追加
            cout<<"reserve: "<<reservation_id<<" "<<flight_seat_price[flight_id][seat_id_column]<<endl;
            reservation_id++;
        }
        if(query=="cancel:"){

        }
        if(query=="seat-search:"){

        }
        if(query=="get-reservations:"){

        }
        if(query=="flight-search:"){

        }
    }
}