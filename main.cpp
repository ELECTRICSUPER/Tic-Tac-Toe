#include <x_si_0.h>
int main()
{
    Tabla tabla(700,800);
    Pozitii pozitiile;
    pozitiile=tabla.obtine_locatiile_playerilor();
    int player_curent=1; //1 e X sgi  2 he 0
    bool totul_ok=true;
    bool win=false;
    bool prima_oara=true;
    int ca_numar=0;
    while(!win)
    {
        totul_ok=false;
        if(player_curent==3)
        {
            player_curent=1;
            totul_ok=false;
        }
        if(player_curent==2)
        {
            Sleep(300);
            if(prima_oara)
            {

                bool e_ok=tabla.Validare_pozitie(5);
                if(e_ok)
                {
                    tabla.Inserare_player_position(2,5);
                    player_curent=1;
                }
                else
                {
                    tabla.Muta();
                    player_curent=1;
                }
                prima_oara=false;
            }
            else
            {
                tabla.Muta();
                totul_ok=true;
                player_curent=1;
            }

        }
        else
        {
            while(!totul_ok)
            {
                bool bun=false;

                while(!bun)
                {
                    ca_numar=tabla.Pozitie_din_mouse_click();
                    if(ca_numar>0 && ca_numar<10)
                    {
                        bun=true;
                    }
                }
                if(tabla.Validare_pozitie(ca_numar))
                {
                    totul_ok=true;
                    tabla.locatie_playeri=tabla.Inserare_player_position(player_curent,ca_numar);
                    player_curent=2;

                }

            }
        }
        tabla.Trasare_linii_tabel();
        win=tabla.Verifica_win();
        if(win)
        {
            outtextxy(getmaxx()/3,getmaxy()/3+getmaxy()/3+10,"AVEM UN CASTIGATOOOR!!");
        }
    }
    getch();
    return 0;
}
