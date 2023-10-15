#include <iostream>
#include <cstring>
#include "HeaderAuthor.hpp"

#if defined(_WIN32)
#include <winsock2.h>

#else
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#endif


using namespace std;



    #if defined(_WIN32)
    WSADATA wd;
    SOCKET soc;

    #else
    int soc;
    #endif
    struct hostent *host;
    struct sockaddr_in serv;
    char hostname_Port[100];

void Port_Scanner(){
    int ports[]={
        20,21,22,23,25,53,67,68,80,110,119,123,143,161,194,443
        };

	#if defined(_WIN32)
        //cout << "[+]Initializing Winsock......\n";
        if(WSAStartup(MAKEWORD(2,2),&wd)!=0){
            //cerr << "[!]Failed to initialize Winsock. Error: " << WSAGetLastError() << endl;
            //cout << "\n";
            //system("pause");
            //return 0;
        }

        else{
            //cout << "[*]Winsock initialization successful!\n";
        }
        #endif



            cout << yellow << "\n\n[" << red << "~" << yellow << "]" << blue << " HostName/IP Address you want to scan: " << reset;
            cin >> hostname_Port;

            cout << yellow << "\n[" << white << "!" << yellow << "]" << blue << " Validating Host/IP......\n" << reset;
            #if defined(_WIN32)
            Sleep(700);

            #else
            sleep(2);
            #endif


            if(isdigit(hostname_Port[0])){
            serv.sin_addr.s_addr = inet_addr(hostname_Port);
            cout << yellow << "[" << white << "!" << yellow << "]" << green << " Valid Host/IP!!!\n" << reset;
            }

            else if((host=gethostbyname(hostname_Port))){
            strncpy((char *)&serv.sin_addr , (char *)host->h_addr_list[0] , sizeof serv.sin_addr);
            cout << yellow << "[" << white << "!" << yellow << "]" << green << " Valid Host/IP!!!\n" << reset;
            }

            else {
                cout << yellow << "[" << white << "!" << yellow << "]" << red << " Invalid Host/IP!!!\n" << reset;
                #if defined(_WIN32)
                system("pause");
                #endif
                exit(0);
            }

                cout << yellow << "\n[" << red << "~" << yellow << "]" << green << " Starting port scan for [" << yellow << hostname_Port << green << "]" << green <<"    Date: " << white
                << __DATE__ << green << "  Time: " << white << __TIME__ << "\n\n" << reset;

                #if defined(_WIN32)
                Sleep(500);

                #else
                sleep(2);
                #endif // defined

                serv.sin_family=AF_INET;

                cout << cyan << " ----------------------------------------------------------\n" << reset;
                cout << cyan << "|" << blue << "           Port" << reset << cyan << "             |           " << blue << "State" << reset << cyan << "             |" << reset << "\n";

                for(int i=0; i<=15; i++){
                        //cout << "[+]Creating socket......\n";
        #if defined(_WIN32)
        if((soc=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))==INVALID_SOCKET){
            //cerr << "[!]Port " << ports << "closed\n";
        }

        else{
            //cout << "[*]Socket creation successful!\n\n";
        }
                serv.sin_port=htons(ports[i]);

                cout << reset << cyan << "|----------------------------|-----------------------------|\n" << reset;


                if(connect(soc,(struct sockaddr*)&serv, sizeof(serv))<0){
                    cout << cyan << "|           " << yellow << ports[i] << red << "                          Closed                 \n";
                }

                else{
                    Sleep(900);
                    cout << cyan << "|           " << yellow << ports[i] << green << "                          Open                   \n";
                }
            }

            cout << reset << cyan << " ----------------------------------------------------------|\n";

            #else
            if((soc=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))== -1){
            //cerr << "[!]Port " << ports << "closed\n";
        }

        else{
            //cout << "[*]Socket creation successful!\n\n";
        }
                serv.sin_port=htons(ports[i]);

                cout << reset << cyan << "|----------------------------|-----------------------------|\n";


                if(connect(soc,(struct sockaddr*)&serv, sizeof(serv))<0){
                    cout << cyan << "|           " << yellow << ports[i] << red << "                          Closed                 \n";
                }

                else{
                    cout << cyan << "|           " << yellow << ports[i] << green << "                          Open                   \n";
                }
            }

            cout << reset << cyan << " ----------------------------------------------------------|\n" << reset;
            #endif

            cout << green << "\n[+] Port Scan Complete!!!\n";

#if defined(_WIN32)
    closesocket(soc);
    WSACleanup();

    #else
    close(soc);
    #endif
}

void header_Windows(),header_Unix(),Prompt(),AboutTool(),Author_Stuffs();

int main(){
    #if defined(_WIN32)
    system("cls");
    header_Windows();

    cout << endl;

    #else
    system("clear");
    header_Unix();
    cout << endl;
    #endif
/*
    Sleep(300);
    cout << green << "\n[~~]";
    Sleep(40);
    cout << " W";
    Sleep(40);
    cout << "e";
    Sleep(40);
    cout << "l";
    Sleep(40);
    cout << "c";
    Sleep(40);
    cout << "o";
    Sleep(40);
    cout << "m";
    Sleep(40);
    cout << "e";
    Sleep(40);
    cout << "!";
    Sleep(40);
    cout << "!";
    Sleep(40);
	*/
    cout << "!\n\n";

    cout << yellow << "[" << red << "1" << yellow << "]" << blue << " Start a scan\n";
    cout << yellow << "[" << red << "2" << yellow << "]" << blue << " About this tool\n";
    cout << yellow << "[" << red << "3" << yellow << "]" << blue << " Exit tool\n";
    cout << yellow << "\n[" << red << "+" << yellow << "]" << cyan << " Select an option: ";
    string opt;
    cout << reset;
    cin >> opt;

    if(opt=="1"){
        #if defined(_WIN32)
        system("cls");
        header_Windows();
        Port_Scanner();
        Prompt();

        #else
        system("clear");
        header_Unix();
        Port_Scanner();
        Prompt();
        #endif // defined
        //Continue;
    }
    else if(opt=="2"){
        #if defined(_WIN32)
        system("cls");
        header_Windows();
        AboutTool();

        #else
        system("clear");
        header_Unix();
        AboutTool();
        #endif // defined
    }
    else if(opt=="3"){
        cout << "[x] Exiting tool....";
        #if defined(_WIN32)
        Sleep(500);

        #else
        sleep(1);
        #endif // defined
        return 0;
    }
    else{
        cout << red << "\n[!] Wrong option!!\n\n";
        #if defined(_WIN32)
        system("pause");
        #endif // defined
        return 0;
    }


}

void Prompt(){
    cout << "\n[-] Do you want to scan another host/IP?[Yes/No]: " << reset;
    string choice;
    cin >> choice;
            while(choice!="Yes"&&choice!="yes"&&choice!="YES"&&choice!="No"&&choice!="no"&&choice!="NO"){
                cout << red << "\n[!] Wrong Option\n\n";
                #if defined(_WIN32)
                Sleep(500);
                system("cls");

                #else
                sleep(1);
                system("clear");
                #endif // defined
                main();
            }
        if (choice=="Yes"||choice=="yes"||choice=="YES"){
            #if defined(_WIN32)
            system("cls");

            #else
            system("clear");
            #endif // defined
            main();
        }
        if (choice=="No"||choice=="no"||choice=="NO"){
            cout << "[x] Exiting tool....";
            #if defined(_WIN32)
            Sleep(500);

            #else
            sleep(1);
            #endif // defined
            exit(0);
        }
        else {
            exit(0);
    }
}

void AboutTool(){
    cout << "\n\nPort-Fin(port finder) is a tool which scans for open and\n";
    cout << "closed port on a website/host. This tool scans the state of the\n";
    cout << "well known/common ports. Below are the ports scanned by this tool\n";
    cout << "20,21,22,23,25,53,67,68,80,110,119,123,143,161,194,443\n";
    cout << "\nNote that the scanning of ports using this tool is not based on the\n";
    cout << "user's specification. It will only be available in the next version of this\n";
    cout << "tool.\n\n";
    cout << "Feel free to contact me @ Facebook: https://web.facebook.com/abdulrahman.abdulazeez.5243/\n";
    cout << "if you notice any bug!!!\n\n";
    cout << "Type and enter 'done' to go back to main menu\n";
    string any;
    cin >> any;

    if(any=="done"||any=="Done"||any=="DONE"){
        #if defined(_WIN32)
        system("cls");

        #else
        system("clear");
        #endif // defined
        main();
    }
    else{
        cout << red << "[!] Wrong Option\n" << reset;
        cout << "[x] Exiting tool.........\n";
        #if defined(_WIN32)
        Sleep(500);

        #else
        sleep(1);
        #endif // defined
        exit(0);
    }

}
