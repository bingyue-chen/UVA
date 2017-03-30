#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){

    map< char , char > mirrored;
    mirrored['A'] = 'A'; mirrored['E'] = '3'; mirrored['H'] = 'H'; mirrored['I'] = 'I'; mirrored['J'] = 'L'; mirrored['L'] = 'J'; mirrored['M'] = 'M';
    mirrored['O'] = 'O'; mirrored['S'] = '2'; mirrored['T'] = 'T'; mirrored['U'] = 'U'; mirrored['V'] = 'V'; mirrored['W'] = 'W'; mirrored['X'] = 'X';
    mirrored['Y'] = 'Y'; mirrored['Z'] = '5'; mirrored['1'] = '1'; mirrored['2'] = 'S'; mirrored['3'] = 'E'; mirrored['5'] = 'Z'; mirrored['8'] = '8';
    map< char , char >::iterator itm;

    string s , str1 , str2;
    int flag1 , flag2 , flag3;

    while( cin >> s ){
        str1 = str2 = s;
        flag1 = flag2 = flag3 = 0;

        reverse( str1.begin() , str1.end() );
        if( s == str1 ) flag1 = 1;

        for ( string::iterator its = str2.begin(); its != str2.end() ; ++its ){
            itm = mirrored.find( *its );
            if( itm != mirrored.end() ) *its = itm->second;
            else {
                    flag3 = 1;
                    break;
            }

        }
        reverse( str2.begin() , str2.end() );
        if( s == str2 && flag3 == 0 ) flag2 = 1;
        cout << s;
        if( flag1 == 0 && flag2 == 0 ) cout << " -- is not a palindrome.\n\n";
        else if( flag1 == 1 && flag2 == 0 ) cout << " -- is a regular palindrome.\n\n";
        else if( flag1 == 0 && flag2 == 1 ) cout << " -- is a mirrored string.\n\n";
        else cout << " -- is a mirrored palindrome.\n\n";
    }
    return 0;
}


