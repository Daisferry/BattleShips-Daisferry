#include <iostream>
#include <string>

using namespace std;

//showp planes
bool show_pl;

//board matrix
int p1[10][10];
int p2[10][10];


//c1=A-J    COORDONATE
//c2=1-10   COORDONATE


//show planes/not show
void showplane()
{
    string a;
    while(true)
    {
        cout<<"\n\n"<<"Doresti sa fie vizibile avioanele? (Y/N):"<<"\n\n";
        getline(cin,a);
        if ((a[0]==89 || a[0]==121) && a[1]=='\0')
        {
            show_pl=true;
            break;
        }
        else if ((a[0]==78 || a[0]==110) && a[1]=='\0')
        {
            show_pl=false;
            break;
        }
        else
        {
            cout<<"\n\nERROR! Raspunsul nu este acceptat...\n\n";
        }
    }
}


// direction set
int directie()
{
    string a;
    while (true)
    {
        cout<<"Alege o directie pt a pozitiona avionul"<<'\n';
        cout<<"1 = jos"<<'\n';
        cout<<"2 = stanga"<<'\n';
        cout<<"3 = dreapta"<<'\n';
        cout<<"4 = sus"<<'\n';
        getline(cin,a);
        if ((a[0]>=49 && a[0]<=52) && a[1]=='\0')
        {
            return a[0]-48;
        }
        else
        {
            cout<<'\n'<<"ERROR! Valoarea nu defineste o directie..."<<'\n'<<'\n';
        }
    }
}


//coordonate pentru A-J (a-j)
int coord_litere()
{
    string a;
    while(true)
    {
        cout<<"Introduceti coordonata numerelor (A-J)(a-j):"<<'\n';
        getline(cin,a);
        if((a[0]>=65 && a[0]<=74) && a[1]=='\0')
        {
            return a[0]-65;
        }
        else if ((a[0]>=97 && a[0]<=106) && a[1]=='\0')
        {
            return a[0]-97;
        }
        else
        {
            cout<<"ERROR! coordonata nu este acceptata..."<<'\n';
        }
    }
}


//coordonate pentru 1-10
int coord_numere()
{
    string a;
    while(true)
    {
        cout<<"Introduceti coordonata numerelor (1-10):"<<'\n';
        getline(cin,a);
        if((a[0]>=49 && a[0]<=57) && a[1]=='\0')
        {
            return a[0]-49;
        }
        else if ((a[0]==49 && a[1]==48) && a[2]=='\0')
        {
            return 9;
        }
        else
        {
            cout<<"ERROR! coordonata nu este acceptata..."<<'\n'<<'\n';
        }
    }
}


//clear board command
void cleargrid(int kiwi[10][10])
{
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++)
        {
            kiwi[i][j]=0;
        }
    }
}


//show particular grid command
void showgrid_particular(int a[10][10])
{
    char n=65;
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<'\n';
    cout<<" *- - - - - - - - - --*;
    cout<<'\n';
    for (int i=0; i<=9; i++)
    {
        cout<<n<<"|";
        n++;
        for (int j=0; j<=9; j++)
        {
            if (show_pl==false)
            {
                //nu arata avioane
                switch (a[i][j])
                {
                // aer
                case 0:
                    cout<<"'"<<" ";
                    break;

                // aer LOVIT
                case 1:
                    cout<<"O"<<" ";
                    break;

                // corp
                case 2:
                    cout<<"'"<<" ";
                    break;

                // corp LOVIT
                case 3:
                    cout<<"x"<<" ";
                    break;

                // cap sus
                case 4:
                    cout<<"'"<<" ";
                    break;

                // cap sus LOVIT
                case 5:
                    cout<<"X"<<" ";
                    break;

                // cap dreapta
                case 6:
                    cout<<"'"<<" ";
                    break;

                // cap dreapta LOVIT
                case 7:
                    cout<<"X"<<" ";
                    break;

                // cap stanga
                case 8:
                    cout<<"'"<<" ";
                    break;

                // cap stanga LOVIT
                case 9:
                    cout<<"X"<<" ";
                    break;

                // cap jos
                case 10:
                    cout<<"'"<<" ";
                    break;

                // cap jos LOVIT
                case 11:
                    cout<<"X"<<" ";
                    break;
                }
            }
            else if (show_pl==true)
            {
                //arata avioane
                switch (a[i][j])
                {
                // aer
                case 0:
                    cout<<"'"<<" ";
                    break;

                // aer LOVIT
                case 1:
                    cout<<"O"<<" ";
                    break;

                // corp
                case 2:
                    cout<<"A"<<" ";
                    break;

                // corp LOVIT
                case 3:
                    cout<<"x"<<" ";
                    break;

                // cap sus
                case 4:
                    cout<<"A"<<" ";
                    break;

                // cap sus LOVIT
                case 5:
                    cout<<"X"<<" ";
                    break;

                // cap dreapta
                case 6:
                    cout<<"A"<<" ";
                    break;

                // cap dreapta LOVIT
                case 7:
                    cout<<"X"<<" ";
                    break;

                // cap stanga
                case 8:
                    cout<<"A"<<" ";
                    break;

                // cap stanga LOVIT
                case 9:
                    cout<<"X"<<" ";
                    break;

                // cap jos
                case 10:
                    cout<<"A"<<" ";
                    break;

                // cap jos LOVIT
                case 11:
                    cout<<"X"<<" ";
                    break;
                }
            }
            else
            {
                cout<<"\nERROR! Nush cum ai ajuns aici... spune-i lu Vlad de eroare\n\n";
            }
        }
        cout<<'\n';
    }
    cout<<'\n';
}


//show all grids command
void showgrids()
{
    cout<<"--------Harta Player 1---------"<<'\n'<<'\n';
    showgrid_particular(p1);

    cout<<"--------Harta Player 2---------"<<'\n'<<'\n';
    showgrid_particular(p2);
}


//attack command
void attack(int player[10][10])
{
    int c1,c2;
    while(true)
    {
        c1=coord_litere();
        c2=coord_numere();
        if (player[c1][c2]%2!=0)
        {
            cout<<"ERROR! locatia a fost atacata deja..."<<'\n'<<'\n';
        }
        else
        {
            // cap sus
            if (player[c1][c2]==4)
            {
                player[c1-1][c2]=3;
                player[c1-1][c2+1]=3;
                player[c1-1][c2+2]=3;
                player[c1-1][c2-1]=3;
                player[c1-1][c2-2]=3;
                player[c1-2][c2]=3;
                player[c1-3][c2]=3;
                player[c1-3][c2+1]=3;
                player[c1-3][c2-1]=3;
            }

            // cap dreapta
            if (player[c1][c2]==6)
            {
                player[c1][c2+1]=3;
                player[c1-1][c2+1]=3;
                player[c1-2][c2+1]=3;
                player[c1+1][c2+1]=3;
                player[c1+2][c2+1]=3;
                player[c1][c2+2]=3;
                player[c1][c2+3]=3;
                player[c1+1][c2+3]=3;
                player[c1-1][c2+3]=3;
            }

            // cap stanga
            if (player[c1][c2]==8)
            {
                player[c1][c2-1]=3;
                player[c1+1][c2-1]=3;
                player[c1+2][c2-1]=3;
                player[c1-1][c2-1]=3;
                player[c1-2][c2-1]=3;
                player[c1][c2-2]=3;
                player[c1][c2-3]=3;
                player[c1-1][c2-3]=3;
                player[c1+1][c2-3]=3;
            }

            //cap jos
            if (player[c1][c2]==10)
            {
                player[c1+1][c2]=3;
                player[c1+1][c2-1]=3;
                player[c1+1][c2-2]=3;
                player[c1+1][c2+1]=3;
                player[c1+1][c2+2]=3;
                player[c1+2][c2]=3;
                player[c1+3][c2]=3;
                player[c1+3][c2-1]=3;
                player[c1+3][c2+1]=3;
            }
            player[c1][c2]++;
            showgrids();
            break;
        }
    }
}


// plane placer command(set-up)
void plane_place(int player[10][10])
{
    int c1,c2,dir;
    cout<<"---faza pentru a pozitiona avioanele---"<<'\n';
    cout<<"Place planes by using coordonates and directions"<<'\n'<<'\n';
    dir=directie();
    switch (dir)
    {
    //sus
    case 1:
        while(true)
        {
            c1=coord_litere();
            c2=coord_numere();
            //verificare pt posibilitate
            if (player[c1][c2]==0 && (c1>=0 && c1<=9) && (c2>=0 && c2<=9))
            {
                if (player[c1-1][c2]==0 && (c1-1>=0 && c1-1<=9) && (c2>=0 && c2<=9))
                {
                    if (player[c1-1][c2+1]==0 && (c1-1>=0 && c1-1<=9) && (c2+1>=0 && c2+1<=9))
                    {
                        if (player[c1-1][c2+2]==0 && (c1-1>=0 && c1-1<=9) && (c2+2>=0 && c2+2<=9))
                        {
                            if (player[c1-1][c2-1]==0 && (c1-1>=0 && c1-1<=9) && (c2+2>=0 && c2+2<=9))
                            {
                                if (player[c1-1][c2-2]==0 && (c1-1>=0 && c1-1<=9) && (c2-2>=0 && c2-2<=9))
                                {
                                    if (player[c1-2][c2]==0 && (c1-2>=0 && c1-2<=9) && (c2>=0 && c2<=9))
                                    {
                                        if (player[c1-3][c2]==0 && (c1-3>=0 && c1-3<=9) && (c2>=0 && c2<=9))
                                        {
                                            if (player[c1-3][c2+1]==0 && (c1-3>=0 && c1-3<=9) && (c2+1>=0 && c2+1<=9))
                                            {
                                                if (player[c1-3][c2-1]==0 && (c1-3>=0 && c1-3<=9) && (c2-1>=0 && c2-1<=9))
                                                {
                                                    player[c1][c2]=4;
                                                    player[c1-1][c2]=2;
                                                    player[c1-1][c2+1]=2;
                                                    player[c1-1][c2+2]=2;
                                                    player[c1-1][c2-1]=2;
                                                    player[c1-1][c2-2]=2;
                                                    player[c1-2][c2]=2;
                                                    player[c1-3][c2]=2;
                                                    player[c1-3][c2+1]=2;
                                                    player[c1-3][c2-1]=2;
                                                    break;
                                                }
                                                else
                                                {
                                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                                }
                                            }
                                            else
                                            {
                                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                            }
                                        }
                                        else
                                        {
                                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                        }
                                    }
                                    else
                                    {
                                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                    }
                                }
                                else
                                {
                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                }
                            }
                            else
                            {
                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                            }
                        }
                        else
                        {
                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                        }
                    }
                    else
                    {
                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                    }
                }
                else
                {
                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                }
            }
            else
            {
                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
            }
        }
        break;

    //stanga
    case 3:
        while(true)
        {
            c1=coord_litere();
            c2=coord_numere();
            //verificare pt posibilitate
            if (player[c1][c2]==0 && (c1>=0 && c1<=9) && (c2>=0 && c2<=9))
            {
                if (player[c1][c2-1]==0 && (c1>=0 && c1<=9) && (c2-1>=0 && c2-1<=9))
                {
                    if (player[c1+1][c2-1]==0 && (c1+1>=0 && c1+1<=9) && (c2-1>=0 && c2-1<=9))
                    {
                        if (player[c1+2][c2-1]==0 && (c1+2>=0 && c1+2<=9) && (c2-1>=0 && c2-1<=9))
                        {
                            if (player[c1-1][c2-1]==0 && (c1-1>=0 && c1-1<=9) && (c2-2>=0 && c2-2<=9))
                            {
                                if (player[c1-2][c2-1]==0 && (c1-2>=0 && c1-2<=9) && (c2-1>=0 && c2-1<=9))
                                {
                                    if (player[c1][c2-2]==0 && (c1>=0 && c1<=9) && (c2-2>=0 && c2-2<=9))
                                    {
                                        if (player[c1][c2-3]==0 && (c1>=0 && c1<=9) && (c2-3>=0 && c2-3<=9))
                                        {
                                            if (player[c1-1][c2-3]==0 && (c1-1>=0 && c1-1<=9) && (c2-3>=0 && c2-3<=9))
                                            {
                                                if (player[c1+1][c2-3]==0 && (c1+1>=0 && c1+1<=9) && (c2-3>=0 && c2-3<=9))
                                                {
                                                    player[c1][c2]=8;
                                                    player[c1][c2-1]=2;
                                                    player[c1+1][c2-1]=2;
                                                    player[c1+2][c2-1]=2;
                                                    player[c1-1][c2-1]=2;
                                                    player[c1-2][c2-1]=2;
                                                    player[c1][c2-2]=2;
                                                    player[c1][c2-3]=2;
                                                    player[c1-1][c2-3]=2;
                                                    player[c1+1][c2-3]=2;
                                                    break;
                                                }
                                                else
                                                {
                                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                                }
                                            }
                                            else
                                            {
                                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                            }
                                        }
                                        else
                                        {
                                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                        }
                                    }
                                    else
                                    {
                                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                    }
                                }
                                else
                                {
                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                }
                            }
                            else
                            {
                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                            }
                        }
                        else
                        {
                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                        }
                    }
                    else
                    {
                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                    }
                }
                else
                {
                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                }
            }
            else
            {
                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
            }
        }
        break;

    //dreapta
    case 2:
        while(true)
        {
            c1=coord_litere();
            c2=coord_numere();
            //verificare pt posibilitate
            if (player[c1][c2]==0 && (c1>=0 && c1<=9) && (c2>=0 && c2<=9))
            {
                if (player[c1][c2+1]==0 && (c1>=0 && c1<=9) && (c2+1>=0 && c2+1<=9))
                {
                    if (player[c1-1][c2+1]==0 && (c1-1>=0 && c1-1<=9) && (c2+1>=0 && c2+1<=9))
                    {
                        if (player[c1-2][c2+1]==0 && (c1-2>=0 && c1-2<=9) && (c2+1>=0 && c2+1<=9))
                        {
                            if (player[c1+1][c2+1]==0 && (c1+1>=0 && c1+1<=9) && (c2+1>=0 && c2+1<=9))
                            {
                                if (player[c1+2][c2+1]==0 && (c1+2>=0 && c1+2<=9) && (c2+1>=0 && c2+1<=9))
                                {
                                    if (player[c1][c2+2]==0 && (c1>=0 && c1<=9) && (c2+2>=0 && c2+2<=9))
                                    {
                                        if (player[c1][c2+3]==0 && (c1>=0 && c1<=9) && (c2+3>=0 && c2+3<=9))
                                        {
                                            if (player[c1+1][c2+3]==0 && (c1+1>=0 && c1+1<=9) && (c2+3>=0 && c2+3<=9))
                                            {
                                                if (player[c1-1][c2+3]==0 && (c1-1>=0 && c1-1<=9) && (c2+3>=0 && c2+3<=9))
                                                {
                                                    player[c1][c2]=6;
                                                    player[c1][c2+1]=2;
                                                    player[c1-1][c2+1]=2;
                                                    player[c1-2][c2+1]=2;
                                                    player[c1+1][c2+1]=2;
                                                    player[c1+2][c2+1]=2;
                                                    player[c1][c2+2]=2;
                                                    player[c1][c2+3]=2;
                                                    player[c1+1][c2+3]=2;
                                                    player[c1-1][c2+3]=2;
                                                    break;
                                                }
                                                else
                                                {
                                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                                }
                                            }
                                            else
                                            {
                                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                            }
                                        }
                                        else
                                        {
                                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                        }
                                    }
                                    else
                                    {
                                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                    }
                                }
                                else
                                {
                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                }
                            }
                            else
                            {
                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                            }
                        }
                        else
                        {
                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                        }
                    }
                    else
                    {
                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                    }
                }
                else
                {
                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                }
            }
            else
            {
                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
            }
        }
        break;

    //jos
    case 4:
        while(true)
        {
            c1=coord_litere();
            c2=coord_numere();
            //verificare pt posibilitate
            if (player[c1][c2]==0 && (c1>=0 && c1<=9) && (c2>=0 && c2<=9))
            {
                if (player[c1+1][c2]==0 && (c1+1>=0 && c1+1<=9) && (c2>=0 && c2<=9))
                {
                    if (player[c1+1][c2-1]==0 && (c1+1>=0 && c1+1<=9) && (c2-1>=0 && c2-1<=9))
                    {
                        if (player[c1+1][c2-2]==0 && (c1+1>=0 && c1+1<=9) && (c2-2>=0 && c2-2<=9))
                        {
                            if (player[c1+1][c2+1]==0 && (c1+1>=0 && c1+1<=9) && (c2+1>=0 && c2+1<=9))
                            {
                                if (player[c1+1][c2+2]==0 && (c1+1>=0 && c1+1<=9) && (c2+2>=0 && c2+2<=9))
                                {
                                    if (player[c1+2][c2]==0 && (c1+2>=0 && c1+2<=9) && (c2>=0 && c2<=9))
                                    {
                                        if (player[c1+3][c2]==0 && (c1+3>=0 && c1+3<=9) && (c2>=0 && c2<=9))
                                        {
                                            if (player[c1+3][c2-1]==0 && (c1+3>=0 && c1+3<=9) && (c2-1>=0 && c2-1<=9))
                                            {
                                                if (player[c1+3][c2+1]==0 && (c1+3>=0 && c1+3<=9) && (c2+1>=0 && c2+1<=9))
                                                {
                                                    player[c1][c2]=10;
                                                    player[c1+1][c2]=2;
                                                    player[c1+1][c2-1]=2;
                                                    player[c1+1][c2-2]=2;
                                                    player[c1+1][c2+1]=2;
                                                    player[c1+1][c2+2]=2;
                                                    player[c1+2][c2]=2;
                                                    player[c1+3][c2]=2;
                                                    player[c1+3][c2-1]=2;
                                                    player[c1+3][c2+1]=2;
                                                    break;
                                                }
                                                else
                                                {
                                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                                }
                                            }
                                            else
                                            {
                                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                            }
                                        }
                                        else
                                        {
                                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                        }
                                    }
                                    else
                                    {
                                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                    }
                                }
                                else
                                {
                                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                                }
                            }
                            else
                            {
                                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                            }
                        }
                        else
                        {
                            cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                        }
                    }
                    else
                    {
                        cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                    }
                }
                else
                {
                    cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
                }
            }
            else
            {
                cout<<"ERROR! locatia nu este buna, incercati iar..."<<'\n'<<'\n';
            }
        }
        break;

    //erroare
    default:
        cout<<'\n'<<"nu stiu cum ai ajuns aici..."<<'\n';
    }

}


//verificare castig p1/p2
int check_victory(int player1[10][10], int player2[10][10])
{
    int i,j,headshots1=0,headshots2=0;


    for (i=0; i<=9; i++)
    {
        for (j=0; j<=9; j++)
        {
            if (player1[i][j]==5 || player1[i][j]==7 || player1[i][j]==9 || player1[i][j]==11)
            {
                headshots1++;
                if (headshots1==3)
                {
                    cout<<'\n'<<'\n'<<'\n'<<"----- PLAYER 2 A CASTIGAT -----"<<'\n'<<'\n'<<'\n';
                    return 1;
                }
            }
        }
    }


    for (i=0; i<=9; i++)
    {
        for (j=0; j<=9; j++)
        {
            if (player2[i][j]==5 || player2[i][j]==7 || player2[i][j]==9 || player2[i][j]==11)
            {
                headshots2++;
                if (headshots2==3)
                {
                    cout<<'\n'<<'\n'<<'\n'<<"----- PLAYER 1 A CASTIGAT -----"<<'\n'<<'\n'<<'\n';
                    return 2;
                }
            }
        }
    }
    return 0;
}


//ask if replay
bool replay()
{
    string a;
    while(true)
    {
        getline (cin,a);
        if ((a[0]==89 || a[0]==121) && a[1]=='\0')
        {
            return true;
        }
        else if ((a[0]==78 || a[0]==110) && a[1]=='\0')
        {
            return false;
        }
        else
        {
            cout<<'\n'<<"ERROR! Raspunsul nu este valabil..."<<'\n'<<'\n';
        }
    }
}


int main()
{
    int xyz;
    while(true)
    {
        //clear board
        cleargrid(p1);
        cleargrid(p2);

        //arata avioanele ca A sau ca '
        showplane();

        showgrids();

        //set-up player 1
        cout<<'\n'<<"---Este Timpul ca Jucatorul 1 sa puna avioanele---"<<'\n';
        for (int i=3; i>=1; i--)
        {
            if (i<3)
            {
                showgrid_particular(p1);
            }
            cout<<'\n'<<"-----"<<i<<" Avioane ramase de pus-----"<<'\n';
            plane_place(p1);
        }

        //set-up player 2
        cout<<'\n'<<'\n'<<'\n'<<'\n'<<"---Este Timpul ca Jucatorul 2 sa puna avioanele---"<<'\n'<<'\n';
        for (int i=3; i>=1; i--)
        {
            showgrid_particular(p2);
            cout<<'\n'<<"-----"<<i<<" Avioane ramase de pus-----"<<'\n';
            plane_place(p2);
        }

        cout<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<"-----Faza de Pozitionare este gata, incepe atacul-----"<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';

        //atacuri
        while (true)
        {
            cout<<'\n'<<"Jucatorul 1 ataca jucatorul 2:"<<'\n';
            //atac p1 > p2
            attack(p2);
            if (check_victory(p1,p2)==2)
            {
                break;
            }
            cout<<'\n'<<"Jucatorul 2 ataca jucatorul 1:"<<'\n';
            //atac p2 > p1
            attack(p1);
            if (check_victory(p1,p2)==1)
            {
                break;
            }
        }

        //replay?
        cout<<'\n'<<'\n'<<'\n'<<"Doresti sa joci iar?(Y/N)"<<'\n'<<'\n'<<'\n';
        bool a;
        a=replay();
        if (a==true)
        {
            cout<<'\n'<<"Restarting..."<<'\n';
            cout<<"\n\n\n\n\n\n\n\n\n";
        }
        else
        {
            break;
        }
    }
    cin>>xyz;
    return 0;
}
