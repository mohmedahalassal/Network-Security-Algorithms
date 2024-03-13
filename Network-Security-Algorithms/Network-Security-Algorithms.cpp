#include<iostream> // mohmedahalassal 
#include<string>

using namespace std;

string Encryption(string s, int k) {
    int sz = s.length(), p=0;
    string ans = "";
    for (int i = 0; i < sz; ++i) {
        if (isupper(s[i])) {
            p = s[i] - 65;
            ans += (char)((p + k) % 26) + 65;
        }
        else if(islower(s[i])){
            p = s[i] - 97;
            ans += (char)((p + k) % 26) + 97;
        }
        else {
            ans += s[i];
        }
    }

    return ans;
}

string Decryption(string s, int k) {
    int sz = s.length(), c = 0;
    string ans = "";
    for (int i = 0; i < sz; ++i) {
        if (isupper(s[i])) {
            c = s[i] - 65;
            ans += (char)((c - k) % 26) + 65;
        }
        else if (islower(s[i])) {
            c = s[i] - 97;
            ans += (char)((c - k) % 26) + 97;
        }
        else {
            ans += s[i];
        }
    }

    return ans;
}

int main() {
    string Message;
    int key;

    cout << "Enter Your Message\n";
    getline(cin, Message);
    cout << "Enter Your Key\n";
    cin >> key;

    cout << "Enter Your choice : \nC. Encryption Message \nP. Decryption Message\n";

    char choice;
    cin >> choice;
    switch (choice) {
    case 'C':
        Message = Encryption(Message, key);
        cout << "The New Message After Encrypt : " << Message<<'\n';
        break;
    case 'P':
        Message = Decryption(Message, key);
        cout << "The New Message After Decrypt : " << Message << '\n';
        break;
    default:
        cout << "Wrong\n";
    }
    return 0;
}
