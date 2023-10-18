#include <bits/stdc++.h>

using namespace std ;

void rabin_karp_algorithm(string text, string pattern){
    int p = 0 , n = text.size() , m = pattern.size() , q=13 ;

    int d=10 , t[n-m] ;
    for(int i = 0 ; i < n-m ; i++){
        t[i] = 0 ;
    }

    for(int i = 0 ; i < m ; i++){
        p = (d*p + pattern[i]-'0') % q ;
        t[0] = (d*t[0] + text[i]-'0') % q ;
    }
    
    int z = pow(d,m-1) ;
    int h = z % q ;
    for(int s = 0 ; s < n-m ; s++){
        cout << p << " " << t[s] << endl ;
        if(p % q == t[s] % q){
            int i ;
            for(i = 0 ; i < m ; i++){
                if(pattern[i] != text[s+i]){
                    break ;   
                }
            }
            if(i == m){
                cout << "pattern found at index : " << s << endl ;
            }
        }
        if(s < n-m){
            t[s+1] = ((t[s] - (text[s+1]-'0')*h)*d + text[s+m+1]-'0') % q ; 
        }
    
        while(t[s+1] < 0){
            t[s+1] += q ;
        }
    }
}

int main() {
    string text , pattern ;
    cout << "enter numeric string: " ;
    getline(cin,text) ;
    cout << "enter pattern to be found in the string: " ;
    getline(cin,pattern) ;

    rabin_karp_algorithm(text,pattern) ;
    return 0 ;
}