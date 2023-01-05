#include<bits/stdc++.h>
using namespace std;

int main(){

    string example = {"This is a sample string for testing!"};
    
    // String Length
    int len=0;
    for(int i=0; example[i]!='\0'; i++){
        len++;
    }
    cout<<"Length of string is: "<<len<<endl;
    cout<<example;

    // String Copy
    string copyStr;
    for(int i=0; example[i]!='\0'; i++){
        copyStr += example[i];
    }
    cout<<endl<<"The copied string is: "<<copyStr<<endl;

    // String Reverse
    int i=0, j=len-1; 
    while(i<j){
        char temp;
        temp = example[i];
        example[i]=example[j];
        example[j]=temp;
        i++;
        j--;
    }
    cout<<endl<<"The reversed string is: "<<example<<endl;

    // String Concatenate
    example = copyStr + example;
    cout<<endl<<example<<endl;
}