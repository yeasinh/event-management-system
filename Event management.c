#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
#include<string.h>


int i,j,k,m,idx,idx1,idx2,idx5,idx4,idx6,ara[1000][1000],n,idx3,idx4,ara1[1000][100];



struct reg
{
    char fname[100];
    char lname[100];
    char email[100];
    char uid[100];
    char pass[100];
    char repass[100];
};

struct log
{
    char email[100];
    char uid[100];
    char pass[100];
};


struct edetails
{
    char uid[100];
    char ename[100];
    char eplace[100];
    char edate[100];
    char epnumber[100];
    char eninfo[100];
};
void registration()
{
    FILE *p;
    struct reg reg1;
    char reg2[100],reg3[100];

            printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter your first name:");
           gets(reg1.fname);
             printf("\n\t\t\t\t\tEnter your last name:");
           gets(reg1.lname);
             printf("\n\t\t\t\t\tEnter your email id:");
           gets(reg1.email);
             printf("\n\t\t\t\t\tEnter your user id:");
           gets(reg1.uid);
           repass1:
             printf("\n\t\t\t\t\tEnter your password:");
           gets(reg1.pass);
             printf("\n\t\t\t\t\tEnter re-password:");
           gets(reg1.repass);


          strcpy(reg2,reg1.uid);
          strcpy(reg3,reg1.uid);



            strcat(reg2,".txt");
            strcat(reg3,"\npl.txt");
p=fopen(reg3,"w");
fclose(p);

            if(strcmp(reg1.pass,reg1.repass)==0)
          {
              p=fopen(reg2,"w");
              fputs(reg1.email,p);
              fputs("\n",p);
              fputs(reg1.pass,p);
              fputs("\n",p);
              fclose(p);
          }
            else
          {
            printf("\n\t\t\t\tYour password is wrong\n");
            goto  repass1;
          }
       return 0;
}

void login(char *str)
{

    FILE *p;
    struct log log1;
    struct reg reg1;
    char log2[100],log3[100][100],log4[100],ch;
    int i;


          printf("\n\n\n\n\n\n\n\t\t\t\t\t\tLog In\n\n");


          printf("\t\t\t\t\t\tEnter your user id:");
           gets(log1.uid);
           wpss1:
          printf("\n\t\t\t\t\t\tEnter your password:");
           gets(log1.pass);
           strcat(log1.pass,"\n");

           strcpy(log2,log1.uid);
           strcat(log2,".txt");

           p=fopen(log2,"r");
           i=0;
           while(!feof(p))
           {
               fgets(log3[i],SIZE,p);
               i++;
               idx=i;
           }

           fclose(p);

      if(strcmp(log3[1],log1.pass)!=0)
 {
     system("cls");
     printf("\n\n\n\n\n\n\n\t\t\t\t\t\tYour password is wrong .\n");



     printf("\t\t\t\t\t\tEnter 1 for try again\n");
     printf("\t\t\t\t\t\tEnter 2 for reset password\n");
   while(1)
        {
        if(kbhit())
        {
     ch=getch();

     if((int)ch==50)
        {
            system("cls");
         printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEnter your email:");
         gets(log1.email);

         strcat(log1.email,"\n");

         if(strcmp(log3[0],log1.email)!=0)
         {
            exit1();
         }
         else
         {
             printf("\n\n\t\t\t\t\t\tEnter your new password");
             gets(log4);

         strcat(log4,"\n");
         strcpy(log3[1],log4);


       p=fopen(log2,"w");
         for(i=0;i<idx;i++)
         {
             fputs(log3[i],p);

         }
         fclose(p);
         }
        goto finish;
      }
      else if((int)ch==49)
      {
         goto wpss1;
      }
      }
      }
      }
       else
     {

     printf("\n\n\n\n\n\t\t\t\t\t\tAccess granted");
     getchar();


     }
finish:

       strcpy(str,log1.uid);
}


void create(char *uid)
{

    FILE *p1,*p2;
    struct edetails ed1;
    char ch,cre[100],cre1[100];
    strcpy(cre,uid);
     strcpy(cre1,uid);
    strcat(cre,".txt");
    strcat(cre1,"pl.txt");
    create1:

         printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEnter c for Creating contest\n");
           printf("\t\t\t\t\t\tEnter w for Creating Workshop\n");
           printf("\t\t\t\t\t\tEnter m for Creating meeting\n");
           printf("\t\t\t\t\t\tEnter o for Creating occasions\n\n");

           printf("\t\t\t\t\t\tEnter your choice:");



           while(1)
           {

           if(kbhit())
           {

        ch=getch();
          if((int)ch==99)
          {
               system("cls");
               p1=fopen("Contest.txt","a");

          }
          else if((int)ch==119)

          {
              system("cls");
               p1=fopen("Workshop.txt","a");
          }
          else if((int)ch==109)
          {
              system("cls");
               p1=fopen("Meeting.txt","a");
          }
          else if((int)ch==111)
          {
             system("cls");

              p1=fopen("Occasion.txt","a");
          }

          p2=fopen(cre,"a");


                 printf("\n\n\t\t\t\t\t\tEnter event name:");
                gets(ed1.ename);


                  printf("\n\t\t\t\t\t\tEnter event place:");
                gets(ed1.eplace);

                  printf("\n\t\t\t\t\t\tEnter event date:");
                gets(ed1.edate);


                  printf("\n\t\t\t\t\t\tEnter participant number:");
                gets(ed1.epnumber);

                  printf("\n\t\t\t\t\t\tNecessary information:");
                gets(ed1.eninfo);


strcpy(ed1.uid,uid);

fputs(cre1,p1);
 fputs("\n",p1);

 fputs(ed1.ename,p1);
 fputs("\n",p1);
 fputs(ed1.ename,p2);
 fputs("\n",p2);

 fputs(ed1.eplace,p1);
 fputs("\n",p1);
 fputs(ed1.eplace,p2);
 fputs("\n",p2);


 fputs(ed1.edate,p1);
 fputs("\n",p1);
 fputs(ed1.edate,p2);
 fputs("\n",p2);


 fputs(ed1.epnumber,p1);
 fputs("\n",p1);
 fputs(ed1.epnumber,p2);
 fputs("\n",p2);


 fputs(ed1.eninfo,p1);
 fputs("\n",p1);
 fputs(ed1.eninfo,p2);
 fputs("\n",p2);

                  fclose(p1);
                  fclose(p2);
                  system("cls");


                  printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEnter m if you want to go to main menu\n");
                  printf("\n\t\t\t\t\t\tEnter c if you want to create event again\n");
                  ch=getch();
                  if((int)ch==109)
                  {
                       system("cls");
                      menuhost(uid);
                  }
                  else if((int)ch==99)
                  {
                      system("cls");
                      goto create1;
                  }

           }
           }
return uid;
}


void modify(char *uid)
{

    char ch;
FILE *p1,*p2;
    char mod2[100],mod4[100],mod[100][100],mod1[100][100],mod3[100][100],mod5[100],mod6[100];
    strcpy(mod5,uid);
    strcpy(mod6,uid);

    strcat(mod5,".txt");
    strcat(mod6,"pl.txt");
modife:



               printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter c for Modifying contest\n");
           printf("\t\t\t\t\tEnter w for Modifying workshop\n");
           printf("\t\t\t\t\tEnter m for Modifying meeting\n");
           printf("\t\t\t\t\tEnter o for Modifying occasions\n");
            printf("\n\t\t\t\t\tEnter your choice:");

           while(1)
           {

           if(kbhit())
           {

        ch=getch();
          if((int)ch==99)
          {

              system("cls");
               p1=fopen("Contest.txt","r");
               strcpy(mod2,"Contest.txt");


          }
          else if((int)ch==119)

          {
              system("cls");
               p1=fopen("Workshop.txt","r");
               strcpy(mod2,"Workshop.txt");
          }
          else if((int)ch==109)
          {
             system("cls");
               p1=fopen("Meeting.txt","r");
               strcpy(mod2,"Meeting.txt");
          }
          else if((int)ch==111)
          {
             system("cls");
             p1=fopen("Occasion.txt","r");
              strcpy(mod2,"Occasion.txt");
          }
          p2=fopen(mod5,"r");

          i=0;
          while(!feof(p1))
          {
             fgets(mod[i],80,p1);
             i++;
             idx=i;
          }
          fclose(p1);
          i=0;
          while(!feof(p2))
          {
             fgets(mod1[i],80,p2);
             i++;
             idx1=i;
          }
          fclose(p2);

          p1=fopen(mod6,"r");
          i=0;

          while(!feof(p1))
          {
              fgets(mod3[i],80,p1);
              i++;
              idx5=i;
          }
          fclose(p1);
          printf("\n\n\n\n\n\n\n\t\t\t\t\tYour Created Event List\n");
          j=0;
          for(i=0;i<idx1-1;i++)
          {
              if(i%5==2)
              {
                printf("\t\t\t\t\tEnter %d for %s",j+1,mod1[i]);
                ara[j][0]=i;
                j++;
              }
          }


          printf("\n\n\n\t\t\t\t\tWhich event you want to modify:\n");

         ch=getch();

         n=(int)ch;
        n=n-49;


        char mod10[100];
        strcpy(mod10,mod1[ara[n][0]]);

          for(i=0;i<idx1-1;i++)
          {
              if(strcmp(mod1[i],mod1[ara[n][0]])==0)
              {
                idx2=i;

                break;
              }
          }
          for(i=0;i<idx-1;i++)
          {
              if(strcmp(mod[i],mod1[ara[n][0]])==0)
              {
                idx3=i;

                break;
              }
          }
          j=0;
          for(i=0;i<idx5-1;i++)
          {
              if(strcmp(mod3[i],mod1[ara[n][0]])==0)
              {
                ara1[j][0]=i-1;

               j++;
               idx4=j;

                break;
              }
          }
system("cls");
printf("\n\n\n\n\n\n\n\t\t\t\t\tYour event details");
          for(i=idx2;i<idx2+5;i++)
          {
             if(i%5==2)
             {
                  printf("\n\n\t\t\t\t\tEvent name:%s",mod1[i]);
             }
             else if(i%5==3)
             {
                  printf("\t\t\t\t\tEvent place:%s",mod1[i]);
             }

             else if(i%5==4)
             {
                  printf("\t\t\t\t\tEvent date:%s",mod1[i]);
             }
             else if(i%5==0)
             {
                  printf("\t\t\t\t\tParticipants number:%s",mod1[i]);
             }
             else if(i%5==1)
             {
                  printf("\t\t\t\t\tNecessary information:%s",mod1[i]);
                  printf("\n");
             }
          }

          printf("\n\n\n\t\t\t\t\tEnter 1 to modify event name.\n");
          printf("\t\t\t\t\tEnter 2 to modify event place.\n");
          printf("\t\t\t\t\tEnter 3 to modify event date.\n");
          printf("\t\t\t\t\tEnter 4 to modify participant number.\n");
          printf("\t\t\t\t\tEnter 5 to modify necessary information.\n");


          ch=getch();
          int w=(int)ch;
          if((int)ch==49)
          {
              printf("\n\t\t\t\t\tEnter new event name:");
              gets(mod4);
              strcat(mod4,"\n");
              strcpy(mod1[idx2],mod4);
              strcpy(mod[idx3],mod4);
          }
          else if((int)ch==50)
          {
               printf("\n\t\t\t\t\tEnter new event place:");
              gets(mod4);
              strcat(mod4,"\n");
              strcpy(mod1[idx2+1],mod4);
              strcpy(mod[idx3+1],mod4);
          }
          else if((int)ch==51)
          {
               printf("\n\t\t\t\t\tEnter new event date:");
              gets(mod4);
              strcat(mod4,"\n");
              strcpy(mod1[idx2+2],mod4);
              strcpy(mod[idx3+2],mod4);
          }else if((int)ch==52)
          {
               printf("\n\t\t\t\t\tEnter new participants number:");
              gets(mod4);
              strcat(mod4,"\n");
              strcpy(mod1[idx2+3],mod4);
              strcpy(mod[idx3+3],mod4);
          }
          else if((int)ch==53)
          {
               printf("\n\t\t\t\t\tEnter new necessary information:");
              gets(mod4);
              strcat(mod4,"\n");
              strcpy(mod1[idx2+4],mod4);
              strcpy(mod[idx3+4],mod4);
          }


          p1=fopen(mod2,"w");
          p2=fopen(mod5,"w");

          for(i=0;i<idx-1;i++)
          {
              fputs(mod[i],p1);
          }
          for(i=0;i<idx1-1;i++)
          {
              fputs(mod1[i],p2);

          }
          fclose(p1);
          fclose(p2);
          char mod7[100];


          for(i=0;i<idx4;i++)
          {
             int l=strlen(mod3[ara1[i][0]]);

              for(j=0;j<l-1;j++)
              {
                  mod7[j]=mod3[ara1[i][0]][j];
              }
mod7[j]='\0';
            p1=fopen(mod7,"r");
            j=0;
            while(!feof(p1))
            {
                fgets(mod[j],80,p1);

                j++;
                idx=j;
            }
            fclose(p1);

              for(j=0;j<idx-1;j++)
              {
                 if( strcmp(mod[j],mod10)==0)
                 {
                     idx1=j;
                   //
                     break;
                 }

              }
              w=w-48;

              if(w==1)
              {
                  strcpy(mod[idx1],mod4);
                  strcpy(mod3[(ara1[i][0])+1],mod4);

              }
              else if(w==2)

              {
                  strcpy(mod[idx1+1],mod4);
              }
               else if(w==3)

              {
                  strcpy(mod[idx1+2],mod4);
              }
               else if(w==4)

              {
                  strcpy(mod[idx1+3],mod4);
              }
               else if(w==5)

              {
                  strcpy(mod[idx1+4],mod4);
              }
              p2=fopen(mod7,"w");

              for(j=0;j<idx-1;j++){



                fputs(mod[j],p1);
              }
                fclose(p1);

          }

          p1=fopen(mod6,"w");
          for(i=0;i<idx5-1;i++)
          {
             fputs(mod3[i],p1);

          }
          fclose(p1);
system("cls");
printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter 1 if you want to go to main menu\n");
                  printf("\n\n\t\t\t\t\tEnter 2 if you want to modify again\n");
                  ch=getch();
                  if((int)ch==49)
                  {
                      system("cls");
                      menuhost(uid);
                  }
                  else if((int)ch==50)
                  {
                      system("cls");
                      goto modife;
                  }
          }
}
}


void delete(char *uid)
{

    FILE *p1,*p2;
     char del[100],del1[100],ch,del2[100][100],del3[100][100],del4[100],del5[100][100];
     strcpy(del,uid);
      strcpy(del4,uid);
     strcat(del,"pl.txt");
     strcat(del4,".txt");

  delete1:
     printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter c for deleting contest\n");
           printf("\t\t\t\t\tEnter w for deleting Workshop\n");
           printf("\t\t\t\t\tEnter m for deleting meeting\n");
           printf("\t\t\t\t\tEnter o for deleting occasions\n");

           printf("\n\t\t\t\t\tEnter your choice:");

           while(1)
           {
               if(kbhit())
               {

          ch=getch();
          if((int)ch==99)
          {
               system("cls");
               p1=fopen("Contest.txt","r");
               strcpy(del1,"Contest.txt");

          }
          else if((int)ch==119)

          {
              system("cls");
               p1=fopen("Workshop.txt","r");
               strcpy(del1,"Workshop.txt");
          }
          else if((int)ch==109)
          {
              system("cls");
               p1=fopen("Meeting.txt","r");
               strcpy(del1,"Meeting.txt");
          }
          else if((int)ch==111)
          {
             system("cls");
             p1=fopen("Occasion.txt","r");
              strcpy(del1,"Occasion.txt");
          }
          p2=fopen(del4,"r");

          i=0;
          while(!feof(p1))
          {
             fgets(del2[i],80,p1);

             i++;
             idx=i;

          }
          fclose(p1);
          i=0;
          while(!feof(p2))
          {
             fgets(del3[i],80,p2);
             i++;
             idx1=i;
          }
          fclose(p2);

          printf("\n\n\n\n\n\n\n\t\t\t\t\tYour Created Event List\n");
          j=0;
          for(i=0;i<idx1-1;i++)
          {
              if(i%5==2)
              {
                printf("\n\t\t\t\t\tEnter %d for %s",j+1,del3[i]);
                ara[j][0]=i;
                j++;
              }
          }


          printf("\n\n\t\t\t\t\tWhich event you want to delete:\n");
         ch=getch();

         n=(int)ch;
        n=n-49;

          for(i=0;i<idx-1;i++)
          {
              if(strcmp(del2[i],del3[ara[n][0]])==0)
              {
                idx3=i;
                break;
              }
          }


          for(i=0;i<idx1-1;i++)
          {
              if(del3[i]==del3[ara[n][0]])
              {
                idx2=i;
                break;
              }
          }
           p1=fopen(del1,"w");
          p2=fopen(del4,"w");

          for(i=0;i<idx-1;i++)
          {
              if(i!=idx3-1 && i!=idx3 && i!=idx3+1 && i!=idx3+2 && i!=idx3+3 && i!=idx3+4 )
              {
                    fputs(del2[i],p1);
              }
          }
          for(i=0;i<idx1-1;i++)
          {
        if(i!=idx2 && i!=idx2+1 && i!=idx2+2 & i!=idx2+3 && i!=idx2+4 )
              {
                    fputs(del3[i],p2);
              }

          }
          fclose(p1);
          fclose(p2);

          p1=fopen(del,"r");
          i=0;
          while(!feof(p1))
          {
            fgets(del2[i],80,p1);
            i++;
            idx=i;
          }
          fclose(p1);
          j=0;
          for(i=1;i<idx-1;i=i+2)
          {
            if(strcmp(del2[i],del3[ara[n][0]])==0)
            {
                ara1[j][0]=i-1;
                j++;
                idx2=j;
            }
          }
          for(i=0;i<idx2;i++)
          {
              char de[100];
            int l=strlen(del2[ara1[i][0]]);

            for(j=0;j<l-1;j++)
            {
                de[j]=del2[ara1[i][0]][j];
            }
            de[j]='\0';
            p1=fopen(de,"r");
             j=0;
             while(!feof(p1))
             {
                 fgets(del5[j],80,p1);
                 j++;
                 idx3=j;
             }
             fclose(p1);
             for(j=0;j<idx3-1;j++)
             {
                 if(strcmp(del5[j],del3[ara[n][0]])==0)
                 {
                     idx4=j;
                     break;
                 }
             }
            p1=fopen(de,"w");
             for(j=0;j<idx3-1;j++)
             {
               if(j!=idx4-1 && j!=idx4 && j!=idx4+1 && j!=idx4+2 && j!=idx4+3 && j!=idx4+4 )
              {
                    fputs(del5[j],p1);
              }

             }
                fclose(p1);

          }
           p1=fopen(del,"w");
           j=0;
           for(i=0;i<idx-1;i++)
           {
               if(i!=ara1[j][0]  && i!=ara1[j][0]+1)
               {

               fputs(del2[i],p1);
               j++;
               }
           }
           fclose(p1);


system("cls");

printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter 1 if you want to go to main menu\n");
                  printf("\n\n\t\t\t\t\tEnter 2 if you want to delete again\n");
                  ch=getch();
                  if((int)ch==49)
                  {
                      system("cls");
                      menuhost(uid);
                  }
                  else if((int)ch==50)
                  {
                       system("cls");
                      goto delete1;
                  }
          }



           }
}

void showlist(char *uid)
{
    FILE *p1,*p2;
    char ch,je2[100][100];
  printf("\n\n\n\n\n\n\n\t\t\t\t\tThere are four types of event.\n\n");

           printf("\n\n\t\t\t\t\tEnter c for the detail list of contest\n");
           printf("\t\t\t\t\tEnter w for the detail list of Workshop\n");
           printf("\t\t\t\t\tEnter m for the detail list of meeting\n");
           printf("\t\t\t\t\tEnter o for the detail list of occasions\n");
            printf("\t\t\t\t\tEnter your choice:");

while(1)
{
    if(kbhit())
    {
            ch=getch();
          if((int)ch==99)
          {
               system("cls");
               p1=fopen("Contest.txt","r");

          }
          else if((int)ch==119)

          {
              system("cls");
               p1=fopen("Workshop.txt","r");
          }
          else if((int)ch==109)
          {
              system("cls");
               p1=fopen("Meeting.txt","r");
          }
          else if((int)ch==111)
          {
             system("cls");

              p1=fopen("Occasion.txt","r");
          }
          i=0;
          while(!feof(p1))
          {
              fgets(je2[i],80,p1);

              i++;
              idx=i;
          }
          fclose(p1);
          for(i=0;i<idx-1;i++)
          {
             if(i%6==1)
             {
                  printf("\t\t\t\t\tEvent name:%s",je2[i]);
             }
             else if(i%6==2)
             {
                  printf("\t\t\t\t\tEvent place:%s",je2[i]);
             }

             else if(i%6==3)
             {
                  printf("\t\t\t\t\tEvent date:%s",je2[i]);
             }
             else if(i%6==4)
             {
                  printf("\t\t\t\t\tParticipants number:%s",je2[i]);
             }
             else if(i%6==5)
             {
                  printf("\t\t\t\t\tNecessary information:%s",je2[i]);
                  printf("\n");
             }
          }
printf("\t\t\t\t\tPress enter to go to main menu");
getchar();
    system("cls");
    menupart(uid);
    }
    }


}

void joinevent(char *uid)
{

    FILE *p1,*p2;

    char je[100],je2[100][100],ch;
    strcpy(je,uid);
    strcat(je,".txt");
join:
      printf("\n\n\n\n\n\n\n\t\t\t\t\tThere are four types of event.\n\n");

           printf("\t\t\t\t\tEnter c for the list of contest\n");
           printf("\t\t\t\t\tEnter w for the list of Workshop\n");
           printf("\t\t\t\t\tEnter m for the list of meeting\n");
           printf("\t\t\t\t\tEnter o the list of occasions\n");
           printf("\t\t\t\t\tEnter your choice:");
while(1)
{
    if(kbhit())
    {

            ch=getch();
          if((int)ch==99)
          {
               system("cls");
               p1=fopen("Contest.txt","r");

          }
          else if((int)ch==119)

          {
              system("cls");
               p1=fopen("Workshop.txt","r");
          }
          else if((int)ch==109)
          {
              system("cls");
               p1=fopen("Meeting.txt","r");
          }
          else if((int)ch==111)
          {
             system("cls");

              p1=fopen("Occasion.txt","r");
          }
          i=0;
          while(!feof(p1))
          {
              fgets(je2[i],80,p1);

              i++;
              idx=i;
          }
          fclose(p1);
           printf("\n\n\n\n\n\n\n\t\t\t\t\tYour choice type event List\n\n");
          j=0;
          for(i=0;i<idx-1;i++)
          {
              if(i%6==1)
              {
                printf("\t\t\t\t\tEnter %d for %s",j+1,je2[i]);
                ara[j][0]=i;
                j++;
              }
          }

           printf("\n\n\t\t\t\t\tWhich event you want to join :\n");

         ch=getch();



         n=(int)ch;
        n=n-49;
        m=ara[n][0];

p1=fopen(je,"a");
        for(i=ara[n][0]-1;i<ara[n][0]+5;i++)
          {
             fputs(je2[i],p1);
          }
          fclose(p1);


char jo[100];
int l=strlen(je2[m-1]);

for(j=0;j<l-1;j++)
{
  jo[j]=je2[m-1][j];

}
jo[j]='\0';

p1=fopen(jo,"a");
fputs(je,p1);
fputs("\n",p1);
fputs(je2[m],p1);
fclose(p1);



           system("cls");
           printf("\n\n\n\n\n\n\n\t\t\t\t\tEnter 1 if you want to go to main menu\n");
                  printf("\n\n\t\t\t\t\tEnter 2 if you want to join another event again\n");
                  ch=getch();
                  if((int)ch==49)
                  {
                      system("cls");
                      menupart(uid);
                  }
                  else if((int)ch==50)
                  {
                       system("cls");
                      goto join;
                  }


       }

}
}


void showlisthost(char *uid)
{
    char ch,sl[100],sl1[100][100];
FILE *p1;

    strcpy(sl,uid);
    strcat(sl,".txt");
    p1=fopen(sl,"r");
i=0;
    while(!feof(p1))
    {
     fgets(sl1[i],80,p1);

  //  i=idx;
 // puts(sl1[i]);
    i++;
    }

fclose(p1);
    for(i=2;i<idx-1;i++)
    {
        if(i%5==2)
        {
      printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEvent name:%s",sl1[i]);
        }
        else if(i%5==3)
        {
      printf("\t\t\t\t\t\tEvent place:%s",sl1[i]);
        }
        else if(i%5==4)
        {
      printf("\t\t\t\t\t\tEvent date:%s",sl1[i]);
        }
        else if(i%5==0)
        {
      printf("\t\t\t\t\t\tParticipant number:%s",sl1[i]);
        }
        else if(i%5==1)
        {
      printf("\t\t\t\t\t\tNecessary Information:%s",sl1[i]);
      printf("\n");
        }
    }
printf("\n\n\t\t\t\t\t\tFor recently added event log in again.");
printf("\n\n\t\t\t\t\t\tPress Enter to go to main menu");
getchar();
system("cls");
    menuhost(uid);
}
void showlistpart(char *uid)
{
    FILE *p;
    char sl[100],sl1[100][1000];
    strcpy(sl,uid);
    strcat(sl,".txt");
    p=fopen(sl,"r");
    i=0;
    while(!feof(p))
    {
        fgets(sl1[i],80,p);
        i++;
        idx=i;

    }
    fclose(p);
printf("\n\n\n\n\n\n\n\t\t\t\t\tYour Joined Event List According to Event Type");
    for(i=3;i<idx-1;i++)
    {
        if(i%6==3)
        {
            printf("\n\n\t\t\t\t\tEvent name:%s",sl1[i]);
        }
        else if(i%6==4)
        {
            printf("\t\t\t\t\tEvent place:%s",sl1[i]);
        }
         else if(i%6==5)
        {
            printf("\t\t\t\t\tEvent date:%s",sl1[i]);
        }
         else if(i%6==0)
        {
            printf("\t\t\t\t\tParticipant Numbers:%s",sl1[i]);
        }
         else if(i%6==1)
        {
            printf("\t\t\t\t\tNecessary Information:%s",sl1[i]);
            printf("\n");
        }
    }
    printf("\n\n\t\t\t\t\tPress Enter to go to main menu");
getchar();
system("cls");
    menupart(uid);
}
void exit1()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tThank You For Using Our System");
    return 0;
}
void menuhost(char *uid)
{

     char ch;

     printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEnter 1 for Event type\n");
       printf("\t\t\t\t\t\tEnter 2 for  Already created event details\n");
       printf("\t\t\t\t\t\tEnter 3 for Modifying event\n");
       printf("\t\t\t\t\t\tEnter 4 for Deleting Event\n");
        printf("\t\t\t\t\t\tEnter 5 for Exit\n");

          printf("\n\t\t\t\t\t\tEnter your choice:\n");
          while(1)
          {
              if(kbhit())
              {
                  ch=getch();

                  if((int)ch==49)
                  {
                      system("cls");
                      create(uid);
                  }
                  else if((int)ch==50)
                  {
                      system("cls");
                      showlisthost(uid);
                  }
                  else if((int)ch==51)
                  {
                      system("cls");
                      modify(uid);
                  }
                  else if((int)ch==52)
                  {
                      system("cls");
                      delete(uid);
                  }
                  else if((int)ch==53)
                  {
                      system("cls");
                      exit1();
                  }

              }
          }
}


void menupart(char *uid)
{

     char ch;

     printf("\n\n\n\n\n\n\n\t\t\t\t\t\tEnter 1 for Event details\n");
       printf("\t\t\t\t\t\tEnter 2 for Joining event\n");
       printf("\t\t\t\t\t\tEnter 3 for Your joined event details\n");

        printf("\t\t\t\t\t\tEnter 4 for Exit\n");

          printf("\n\t\t\t\t\t\tEnter your choice:\n");
          while(1)
          {
              if(kbhit())
              {
                  ch=getch();

                  if((int)ch==49)
                  {
                      system("cls");
                      showlist(uid);
                  }
                  else if((int)ch==50)
                  {
                      system("cls");
                      joinevent(uid);
                  }
                  else if((int)ch==51)
                  {
                      system("cls");
                      showlistpart(uid);
                  }

                  else if((int)ch==52)
                  {
                      system("cls");
                      exit1();
                  }

              }
          }
}
#include<stdio.h>

int main()
{
int i,m=0,n;
char ch1[100][1000],ch,uid[100];
system("color 1");

while(1){
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for(i=75-m;i>0;i--)
    {
        strcat(ch1[m]," ");
    }
        strcat(ch1[m],"Welcome To Event Management");
puts(ch1[m]);
system("cls");

m++;
if(m==75)
{

   goto nxt;
}
}

nxt:
system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter 1 to Create Event ");
    printf("\n\t\t\t\t\tEnter 2 to Join Event ");
    printf("\n\t\t\t\t\tEnter your choice :");

    while(1)
    {

    if(kbhit())
    {
        system("cls");
        ch=getch();
        if((int)ch==49)
        {
             printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter 1 to Register if you are not registered  ");
             printf("\n\t\t\t\t\tEnter 2 to Log in ");
             printf("\n\t\t\t\t\tEnter your choice :");
             ch=getch();
             if((int)ch==49)
             {
                 system("cls");
                 registration();
                 system("cls");
                 login(uid);
             }
             else if((int)ch==50)
             {
                 system("cls");
                 login(uid);
             }
             system("cls");


             menuhost(uid);




        }
        else if((int)ch==50)
        {
           printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter 1 to Register if you are not registered  ");
             printf("\n\t\t\t\t\tEnter 2 to Log in ");
             printf("\n\t\t\t\t\tEnter your choice :");
             ch=getch();
             if((int)ch==49)
             {
                 system("cls");
                 registration();
                 system("cls");
                 login(uid);
             }
             else if((int)ch==50)
             {
                 system("cls");
                 login(uid);
             }
             system("cls");
             menupart(uid);

        }
    }




    }
}

