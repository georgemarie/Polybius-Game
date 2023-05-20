// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Polybius Square Cipher
// Program Description: program to encrypt and decrypt a message
// Last Modification Date:
// Author : George marie demyan
// ID : 20210106

#include <iostream>
#include <algorithm>
using namespace std;
// first we define array contain 5 indexes
int arr[5];
int Find (int x)
// this function used to know that the number that want to be encrypted which number in the 2D array that get its index and then go to conditions
{
    for(int i=0; i<5; i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int flag =1;
    while (flag ==1)
    {
        cout<<"What do you like to do today?\n1-Encrypt a massage.\n2-Decrypt a massage.\n3-End.\n";
        int choice;
        cin>>choice;
        // here we do a swich case to know which case the user want and make user choose.
        switch (choice)
        {
            case 1 :
            //here in case 1 if the user want to encrypt the message from alphabitic.
            {
                for(int i=0; i<5; i++)
                {
                    cout << "please enter index " << i << " in the array : " << endl ;
                    cin >> arr[i];
                    // loop to fill the array with the key that user want.
                }
                string str ;
                cout << "please enter string you want to Encrypt : ";
                cin.ignore();
                getline(cin , str);
                str.erase(remove(str.begin(), str.end(), ' '), str.end());

                for (int i = 0 ; i<=str.length() ; ++i)
                {
                    str[i] = toupper(str[i]);
                }
                // here the user enter a string and we remove spaces and make all alphabitic word in uppercase.
                for(int i=0; i<str.length(); i++)
                {
                // this for loop used to loop on each character of the word.
                // from the table we assume that the final word in 2D array can get the word before it
                // by using ASCII minus we can get the that before ASCII of character 'E'
                //first will equal to zero that mean we are in arr[0] in the first array
                // then we minus this character ASCII from ASCII of 'A' we get the number exactly
                    int first = 0, second = 0;
                    if(str[i]<='E')
                    {
                        first = 0;
                        second =str[i]-'A';
                    }
                    // if ASCII are less than or equal ASCII of 'K' and greater than ASCII of 'E'
                    //then we kan minus its ASCII from 'A' and also minus 5 from them
                    //first will equal to 1 that mean we are in arr[1] in the first array
                    else if(str[i]<='K')
                    {
                        first = 1;
                        second =str[i]-'A'-5;
                        if(str[i]=='K'||str[i]=='J')
                        {
                            second-=1;
                        }
                    }
                        // if ASCII are less than or equal ASACII of 'P' and greater than ASCII of 'K'
                        // then we kan minus its ASCII from 'A' and also minus 11 from them
                        //first will equal to 2 that mean we are in arr[2] in the first array
                        else if(str[i]<='P')
                    {
                        first = 2;
                        second =str[i]-'A'-11;
                    }
                        // if ASCII are less than or equal ASACII of 'u' and greater than ASCII of 'p'
                        //then we kan minus its ASCII from 'A' and also minus 16 from them
                        //first will equal to 3 that mean we are in arr[3] in the first array
                        else if(str[i]<='U')
                    {
                        first = 3;
                        second =str[i]-'A'-16;
                    }
                        // if ASCII are less than or equal ASACII of 'Z' and greater than ASCII of 'U'
                        //then we kan minus its ASCII from 'A' and also minus 21 from them
                        //first will equal to 4 that mean we are in arr[4] in the first array
                    else if(str[i]<='Z')
                    {
                        first = 4;
                        second =str[i]-'A'-21;
                    }
                    cout <<arr[first]<<arr[second] ;
                }
                cout<<endl;
                break;
            }
            case 2:
            {
                //here if user choose to decrypt the message from numbers to alphabitic.
                for(int i=0; i<5; i++)
                {
                    cout << "please enter index " << i << " in the array : " << endl ;
                    cin>>arr[i];
                    // used to fill the array indexes.
                }
                string str1;
                cout << "please enter the numbers you want to Decrypt : ";
                cin.ignore();
                getline(cin , str1);
                str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
                // here to take the string as numbers and remove spaces if presence between them.
                for(int i=0; i<str1.length(); i+=2)
                {
                    // first and second are two successive number taken by this loop and converted to integer
                    //then go to function find and make first and second are the indexes in 2D array
                    int first = Find(str1[i]-'0');
                    int second = Find(str1[i+1]-'0');
                    // here to convert the number from string to integer and call function find and put the number.
                    //then return the value of first and second and check some conditions.
                    char String;
                    if(first==0)
                    {
                        String = 'A'+ second;
                        //if first = 0 then it indicate that its in first index in array that indicate its in first row
                        //which is from A to E
                        //string this get the alphabit by adding ASCII of 'A' as its in first row in 2D array
                        //string here will equal ASCII of 'A' + second that come from the function find index.
                    }
                    else if(first==1)
                        //if first = 1 then it indicate that its in second index in array that indicate its in secod row
                        //which is from F to K
                        // we put extra condition to get K as I&J have same key
                        //string here will equal ASCII of 'A' + second that come from the function find index + 6.
                    {
                        String = 'A'+ second+5;
                        if(second==4)
                        {
                            String = 'A'+ second+6;
                        }
                    }
                    else if(first==2)
                        //if first = 2 then it indicate that its in third index in array that indicate its in third row
                        //which is from L to P
                        //string here will equal ASCII of 'A' + second that come from the function find index + 11.
                    {
                        String = 'A'+ second+11;
                    }
                    else if(first==3)
                        //if first = 3 then it indicate that its in fouth index in array that indicate its in fourth row
                        //which is from Q to U
                        //string here will equal ASCII of 'A' + second that come from the function find index + 16.
                    {
                        String = 'A'+ second+16;
                    }
                    else if(first==4)
                        //if first = 4 then it indicate that its in fifth index in array that indicate its in fifth row
                        //which is from V to Z
                        //string here will equal ASCII of 'A' + second that come from the function find index + 21.
                    {
                        String = 'A'+ second+21;
                    }
                    cout <<String ;
                }
                cout<<endl;
                break;
            }
            case 3:
                flag = 0;
                break;
            default:
                cout << "Wrong choice\n";
        }

    }
    return 0;
}