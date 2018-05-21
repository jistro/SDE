#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DATA 5600
////////////////////////datos globales//////////////////////
struct datos
{
  char nombre[60];
  char facultad[100];
  int matricula;
  int anno_insc;
  float cal[6];
  int sem_cursados;
}k;

struct datos *alumnos[5600]; //*5
int llave_fin,anno,mat;
////////////////////////////////////////////////////////////

//////////////////////////estetica//////////////////////////
void muestrayborra ()
{
  printf("\n");
  system("pause");
  system("cls");
}
void borrar()
{
  system("cls");
}
void error()
{
  cuadrado(12,1);
  printf("   ERROR!   ");
  cuadrado(12,0);
  muestrayborra();
}
/*
  notas de cuadrado:
                      1- para iniciar
                      0- para cerrar
                      2- solo linea
                      3- un cuadro sin salto de linea y sin espacio
                      nunca agregar \n
*/
int cuadrado(int max, int flag)
{
  int i;
  switch (flag)
  {
    case 1:
            for (i=0;i<max+4;i++)
              printf("%c",219);
            printf("\n");
            printf("%c ",219);
            break;

    case 0:
            printf(" %c ",219);
            printf("\n");
            for (i=0;i<max+4;i++)
              printf("%c",219);
            printf("\n");
            break;

    case 2:
            for (i=0;i<max;i++)
              printf("%c",219);
            printf("\n");
            break;
    case 3:
            for (i=0;i<max;i++)
              printf("%c",219);
            break;

    default:
            for (i=0;i<3;i++)
              printf("%c",219);
            printf("Error");
            for (i=0;i<3;i++)
              printf("%c",219);
            break;
  }
}
////////////////////////////////////////////////////////////

///////////////////////subrogramas//////////////////////////
void ingreso(int llave_fin, int anno, int matri)
{
  int i,j,flag_cal,cont_cursados=0;
  float c;
  struct datos *temp;
    temp = (struct datos *) malloc (sizeof(struct datos));
  	if (temp != NULL)
  	{
      ////////////////////////////datos////////////////////////////

  	 	temp->anno_insc=anno;
  		temp->matricula=matri;
  	  fflush(stdin);
      printf("Ingrese el nombre del alumno\n");
      printf("Nombre: ");
      gets(temp->nombre);
      fflush(stdin);
      printf("Ingrese el nombre de su facultad\n");
      printf("Facultad: ");
      gets(temp->facultad);
      fflush(stdin);
      printf("Ingrese la calificacion por semestre del alumno\nSi no ha cursado ese semestre ponga 0\n");
      cont_cursados=0;
      for (i=0;i<6;i++)
      {
        do
        {
          flag_cal=0;
          printf("Semestre %d: ", i+1);
          scanf("%f", &c);
          if ((c>=5&&c<=10)||c==0)
            flag_cal=1;
        } while(flag_cal==0);

        if (c>=5)
        {
          cont_cursados++;
          temp->cal[i]=c;
        }
        if (c==0)
        {
          temp->cal[i]=0;
          i=6;
        }
      }
      if (cont_cursados!=6)
      {
        for (i=cont_cursados;i<6;i++)
        {
          c=0;
          temp->cal[i]=c;
        }
      }
      temp->sem_cursados=cont_cursados;
      /////////////////////////////////////////////////////////////


      //si aun no hay datos
      if (alumnos[llave_fin]==NULL)
      {
        alumnos[llave_fin]=temp;
      }
      else //si hay datos en el entonces
      {
        //si el nodo es igual a la matricula solamente lo reescribe
        if (alumnos[llave_fin]->matricula==matri)
        {
          alumnos[llave_fin]=temp;
        }
        else //pero si no es asi
        {
          //mensaje de error solo para debug
          //printf("error de data\n");
          //inicia contador y averigua lugares vacios
          int r=1;
          //mensaje de error solo para debug
          //printf("%d ",llave_fin+r);
          while (alumnos[llave_fin+r]!=NULL)
          {
            r++;
            //mensaje de error solo para debug
            //printf("%d ",llave_fin+r);
          }
          //lo ingresa en esa zona
          alumnos[llave_fin+r]=temp;
        }
      }
  	}
  	else
    {
      cuadrado(21,1);
  	  printf("Memoria insuficiente!");
      cuadrado(21,0);
    }
}


void ver(int llave_fin,int matri)
{
  //si hay datos
  if (alumnos[llave_fin]!=NULL)
  {
    //si en el primer lugar de memoria es igual a la matricula
    if (alumnos[llave_fin]->matricula==matri)
    {
      int i;
      float suma=0,prom_fin;
      printf("Nombre: %s\n", alumnos[llave_fin]->nombre);
      printf("Facultad: %s\n", alumnos[llave_fin]->facultad);
      if (alumnos[llave_fin]->sem_cursados!=0)
      {
        printf("Semestres cursados: %d\n", alumnos[llave_fin]->sem_cursados);
        for (i=0;i<6;i++)
        {
          if (alumnos[llave_fin]->cal[i]!=0)
          {
            printf("Semestre %d: %.2f\n",i+1,alumnos[llave_fin]->cal[i]);
            suma=suma+alumnos[llave_fin]->cal[i];
          }
        }
        printf("Promedio: %f\n",(suma/alumnos[llave_fin]->sem_cursados));
      }
      else
      {
        printf("El alumno es de nuevo ingreso\n");
      }

    }
    //si  no es asi
    else
    {
      //printf("error de dataaaaaa\n");
      int r=0,flag_corte=0,flag_end=0;
      //printf("%d ",llave_fin+r);
      do
      {
        r++;
        //printf("%d ",llave_fin+r);
        if (llave_fin+r==5600)
        {
          //printf("\n a su maximo\n");
          flag_corte=1;
          flag_end=1;
        }
        if (flag_end==0)
        {
          if (alumnos[llave_fin+r]!=NULL)
          {
            if (alumnos[llave_fin+r]->matricula==matri)
            {
              flag_end=1;
              //printf("Encontrado!!\n");
            }
          }

        }
      } while(flag_end==0);

      if (flag_corte==0)
      {
        int i;
        float suma=0,prom_fin;
        printf("Nombre: %s\n", alumnos[llave_fin+r]->nombre);
        printf("Facultad: %s\n", alumnos[llave_fin+r]->facultad);
        if (alumnos[llave_fin+r]->sem_cursados!=0)
        {
          printf("Semestres cursados: %d\n", alumnos[llave_fin+r]->sem_cursados);
          for (i=0;i<6;i++)
          {
            if (alumnos[llave_fin+r]->cal[i]!=0)
            {
              printf("Semestre %d: %.2f\n",i+1,alumnos[llave_fin+r]->cal[i]);
              suma=suma+alumnos[llave_fin+r]->cal[i];
            }
          }
          printf("Promedio: %f\n",(suma/alumnos[llave_fin+r]->sem_cursados));
        }
        else
        {
          printf("El alumno es de nuevo ingreso\n");
        }
      }
      else
      {
        cuadrado(21,1);
        printf("No existe informacion");
        cuadrado(21,0);
      }


    }
  }
  else
  {
    cuadrado(21,1);
    printf("No existe informacion");
    cuadrado(21,0);
  }
}
void borrado(int llave_fin,int matri)
{
  if (alumnos[llave_fin]!=NULL)
  {
    if (alumnos[llave_fin]->matricula==matri)
    {
      char resp;
      int flag_r=0;
      do
      {
        printf("Esta segurro borrar los datos de %d s/n\nRespuesta: ", matri);
        fflush(stdin);
        resp=getchar();
        fflush(stdin);
        if (resp=='s' || resp=='n')
          flag_r=1;
      } while(flag_r==0);
      if (resp=='s')
      {
        if (alumnos[llave_fin+1]==NULL)
        {
          alumnos[llave_fin]=NULL;
        }
        else
        {
          int cont_memo=0;
          int i;
          cont_memo=0;
          for (i=llave_fin+1;i<llave_fin+5;i++)
          {
            if (alumnos[i]!=NULL)
            {
                cont_memo++;
            }
          }
          struct datos *temp;
          //printf("Moviendo %d espacios\n", cont_memo);
          if (cont_memo==1)
          {
            alumnos[llave_fin]=alumnos[llave_fin+cont_memo];
            alumnos[llave_fin+cont_memo]=NULL;

          }
          else
          {
            for (i=0;i<cont_memo;i++)
            {
              alumnos[llave_fin+i]=alumnos[llave_fin+(i+1)];
            }
            alumnos[llave_fin+cont_memo]=NULL;
          }

        }
      }

    }
    else
    {
      //printf("error de dataaaaaa\n");
      int r=0,flag_corte=0,flag_end=0;
      //printf("%d\n",llave_fin+r);
      do
      {
        r++;
        //printf("%d\n",llave_fin+r);
        if (llave_fin+r==5600)
        {
          //printf("a su maximo\n");
          flag_corte=1;
          flag_end=1;
        }
        if (flag_end==0)
        {
          if (alumnos[llave_fin+r]!=NULL)
          {
            if (alumnos[llave_fin+r]->matricula==matri)
            {
              flag_end=1;
              //printf("Encontrado!!\n");
            }
          }

        }
      } while(flag_end==0);

      if (flag_corte==0)
      {
        char resp;
        int flag_r=0;
        do
        {
          //y el caso cuando se elimine el principal?
          printf("Esta segurro borrar los datos de %d s/n\nRespuesta: ", matri);
          fflush(stdin);
          resp=getchar();
          fflush(stdin);
          if (resp=='s' || resp=='n')
            flag_r=1;
        } while(flag_r==0);
        if (resp=='s')
        {
          //se suma el recorrido
          llave_fin=llave_fin+r;

          if (alumnos[llave_fin+1]==NULL)
          {
            alumnos[llave_fin]=NULL;
          }
          else
          {
            int cont_memo=0;
            int i;
            cont_memo=0;
            for (i=llave_fin+1;i<llave_fin+5;i++)
            {
              if (alumnos[i]!=NULL)
              {
                  cont_memo++;
              }
            }
            struct datos *temp;
            //printf("Moviendo %d espacios\n", cont_memo);
            if (cont_memo==1)
            {
              alumnos[llave_fin]=alumnos[llave_fin+cont_memo];
              alumnos[llave_fin+cont_memo]=NULL;

            }
            else
            {
              for (i=0;i<cont_memo;i++)
              {
                alumnos[llave_fin+i]=alumnos[llave_fin+(i+1)];
              }
              alumnos[llave_fin+cont_memo]=NULL;
            }

          }
        }
      }
      else
      {
        cuadrado(21,1);
        printf("No existe informacion");
        cuadrado(21,0);
      }
    }
  }
  else
  {
    cuadrado(21,1);
    printf("No existe informacion");
    cuadrado(21,0);
  }

}
////////////////////////////////////////////////////////////

/////////////////////////main//////////////////////////////
int main ()
{
  int num_alumnos=0;
  int men1, men2;
  char mat1[9], mat_anno[4],mat_id[5],llave1_b[2],llave2_b[3];
  int id,llave1,llave2,primo=17;
  char mat_f[9];
  int flag_mat=0;
  int i,j;
  char resp_sal;
  int flag_sal=0;

  for (i=0;i<5600;i++)
  	alumnos[i]=NULL;

  do
  {
    cuadrado(25,1);
    printf("          Menu           ");
    cuadrado(25,0);
    cuadrado(25,1);
    printf("1 | Ingreso de matricula  ");
    cuadrado(1,2);
    cuadrado(1,3);
    printf(" 2 | ver info de matricula ");
    cuadrado(1,2);
    cuadrado(1,3);
    printf(" 3 | borrado de datos      ");
    cuadrado(1,2);
    cuadrado(1,3);
    printf(" 4 | salir                ");
    cuadrado(25,0);
    scanf("%d", &men1);
    switch (men1)
    {
      case 1: //agrega
              do
              {
                flag_mat=0;
                cuadrado(29,1);
                printf("ingrese matricula a registrar");
                cuadrado(29,0);
                scanf("%d",&mat);
                if (mat>=200000000&&mat<=201999999)
                  flag_mat=1;
                else
                  error();
                borrar();
              } while(flag_mat!=1);
              sprintf(mat1, "%d", mat);
              for(i=0;i<4;i++)
                 mat_anno[i]=mat1[i];
              j=0;
              for(i=4;i<=9;i++)
              {
                  mat_id[j]=mat1[i];
                  j++;
              }
              anno = atoi (mat_anno);
              for(i=0;i<2;i++)
                llave1_b[i]=mat_id[i];
              j=0;
              for(i=2;i<=5;i++)
              {
                  llave2_b[j]=mat_id[i];
                  j++;
              }
              llave1 = atoi (llave1_b);
              llave2 = atoi (llave2_b);
              //printf("%d %d %d\n",anno,llave1,llave2);
              llave_fin=(llave1+llave2+(anno-2000))*5;
              //printf("-%d-",llave_fin);
              ingreso(llave_fin,anno,mat);
              muestrayborra();
              break;
      case 2: //busca
              do
              {
                flag_mat=0;
                cuadrado(26,1);
                printf("ingrese matricula a buscar");
                cuadrado(26,0);
                scanf("%d",&mat);
                if (mat>=200000000&&mat<=201999999)
                  flag_mat=1;
                else
                  error();
                borrar();
              } while(flag_mat!=1);
              sprintf(mat1, "%d", mat);
              for(i=0;i<4;i++)
                 mat_anno[i]=mat1[i];
              j=0;
              for(i=4;i<=9;i++)
              {
                  mat_id[j]=mat1[i];
                  j++;
              }
              anno = atoi (mat_anno);
              for(i=0;i<2;i++)
                llave1_b[i]=mat_id[i];
              j=0;
              for(i=2;i<=5;i++)
              {
                  llave2_b[j]=mat_id[i];
                  j++;
              }
              llave1 = atoi (llave1_b);
              llave2 = atoi (llave2_b);
              printf("%d%d%d\n",anno,llave1,llave2);

              llave_fin=(llave1+llave2+(anno-2000))*5;
              //printf("-%d-",llave_fin);
              ver(llave_fin,mat);
              muestrayborra();
              break;
      case 3: //borra
                do
                {
                  flag_mat=0;
                  cuadrado(26,1);
                  printf("ingrese matricula a borrar");
                  cuadrado(26,0);
                  scanf("%d",&mat);
                  if (mat>=200000000&&mat<=201999999)
                    flag_mat=1;
                  else
                    error();
                  borrar();
                } while(flag_mat!=1);
                sprintf(mat1, "%d", mat);
                for(i=0;i<4;i++)
                   mat_anno[i]=mat1[i];
                j=0;
                for(i=4;i<=9;i++)
                {
                    mat_id[j]=mat1[i];
                    j++;
                }
                anno = atoi (mat_anno);
                for(i=0;i<2;i++)
                  llave1_b[i]=mat_id[i];
                j=0;
                for(i=2;i<=5;i++)
                {
                    llave2_b[j]=mat_id[i];
                    j++;
                }
                llave1 = atoi (llave1_b);
                llave2 = atoi (llave2_b);
                //printf("%d %d %d\n",anno,llave1,llave2);

                llave_fin=(llave1+llave2+(anno-2000))*5;
                //printf("-%d-",llave_fin);
                borrado(llave_fin,mat);
                muestrayborra();
                break;
      case 4:   //para salir
                do
                {
                  //y el caso cuando se elimine el principal?
                  cuadrado(28,1);
                  printf("Desea salir del programa s/n");
                  cuadrado(28,0);
                  fflush(stdin);
                  resp_sal=getchar();
                  fflush(stdin);
                  if (resp_sal=='s' || resp_sal=='n')
                    flag_sal=1;
                } while(flag_sal==0);
                if (resp_sal=='s')
                {
                  borrar();
                  printf("Gracias por usar el programa");
                }
                else
                {
                  men1=5;
                  borrar();
                }
      default: //si la resp. fue erronea
                break;
    }
  } while (men1!=4);
}
