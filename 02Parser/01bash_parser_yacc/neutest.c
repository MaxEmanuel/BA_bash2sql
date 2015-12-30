     #include <ctype.h>
     #include <stdio.h>
     #include <stdlib.h>
     #include <unistd.h>
     
int ausgeben(int* feld)
{
	int i=0;
	for (i=0;i<6;i++)
		printf("%d\n",feld[i]);
}

int
     main (int argc, char **argv)
     {
	int feld[]={1,2,3,4,5,6};
        char* e="d1,2,3,4,5";
	int crtf=0;
	int a,b,ret;
        do{
                e++;
                ret=sscanf(e,"%d-%d",&a,&b);
		/* felder beginnen bei 0*/
		a--; b--;
                if(ret==0)/*error*/
                        return -1;
		/* von - bis  */
                else if(ret==2){
                        for(;a<=b;a++)
                           feld[crtf++]=feld[a];
                }/*einzelne Auswahl */else{
                        feld[crtf++]=feld[a];
                }
                while((*e>='0' && *e<='9')||*e=='-')
                        e++;
        }while(*e==',');
	feld[crtf]=0;

	ausgeben(feld);
     }
