/* ta te ti*/
#include<stdio.h>
#include<time.h> // declaramos la libreria tiempo, así podremos utilizar esta función (para los números aleatorios que usan esta función)
void loop(char c [3][3]);
void intro_utilizada_una_ves (char c [3][3]);
void tablero(char c[3][3]);
void intro_valores_yo(char c [3][3]);
void intro_ia(char c[3][3]);
int victoria(char c[3][3]);
int main()
{
	char c [3][3];    // sera el tablero
	loop (c);         // Llama a todas los funciones fundamentales y hace un refresco de pantalla
	
	
	system ("pause");
	return 0;
}
void loop (char c [3][3])
{
	// haremos un contador, para cuando el contador llegue a 10 y supere a 9, debe salirse
	int i,j;
	
	i=0;
	
	intro_utilizada_una_ves(c);
	
	do{
		system("cls");                      // borra todo en pantalla
		// elegiremos los turnos entre usuario y aleatorio
		tablero(c);
		if (i % 2 == 0){
		
			intro_valores_yo(c);
			
		}else{
			intro_ia(c);
		}
		j = victoria(c);
		
		i++;
		
	}while(i <= 9 && j == 2);
	system("cls");
	tablero(c);
	if(j==0){
		printf("\n ¡¡¡ Felicidades eres el ganador!!!");
	}else if(j==1){
		printf("\n Has perdido, sigue intentando");
	}else{
		printf("\n Has empatado");
	}
	
}
void intro_utilizada_una_ves (char c[3][3])
{
	int i,j;
	char aux;         // los caracteres que introduciremos en la matriz seran de manera auxiliar
	aux = '1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			c [i][j] = aux ++;
		}
	}
}
void intro_valores_yo(char c [3][3]) // función para introducir los valores
{
	int i,j,k;
	char jugada;
	do{
		do{
			printf("\n x es tu jugada, o es la jugada del bot");
			printf("\n coloca tu jugada:");
			fflush(stdin);   
			scanf("%c",&jugada);                     // antes de un scanf, con una varibale char, poner fflush(stdin);
		}while(jugada<'1'|| jugada>'9');                // el valor ingresado debe estar entre 1-9
		
		     k=0;
			                                        
		 switch(jugada){                             // para comprobar si el número esta repetido
		 	case '1':{
		 		  i=0;                               // i y j, valen cero en la matriz 1, ya que se cuenta desde 0,1,2
		 		  j=0;
		 		  if(c[i][j]=='x' || c[i][j]=='o' ){   // significa casillas ocupadas
		 		  	k=1;                             // utilizamos k como escape
		 		  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
				break;
		     }
			 case '2':{
			 	  i=0;
			 	  j=1;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
				break;
			 }
			 case '3':{
			 	  i=0;
			 	  j=2;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
			 case '4':{
			 	  i=1;
			 	  j=0;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
			 case '5':{
			 	  i=1;
			 	  j=1;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
			 case '6':{
			 	  i=1;
			 	  j=2;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
			 case '7':{
			 	  i=2;
			 	  j=0;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
			 case '8':{
			 	  i=2;
			 	  j=1;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
			 case '9':{
			 	  i=2;
			 	  j=2;
			 	  if(c[i][j]=='x'||c[i][j]=='o'){
			 	  	k=1;
			 	  	printf("\n Casilla ocupada, intente con otro numero por favor");
				   }
			 	
			 	
				break;
			 }
		}
		                                            
	}while(k==1); // esta bufircación se repetira cada vez que k ===1, ya que k es el auxiliar y si k es usado significa que esa casilla ya estaba ocupada
  
   c[i][j]='x';         	
}

void intro_ia(char c[3][3])   // Aquí utilizaremos números aleatorios
{            
    int i,j, k;
    srand(time(NULL));        // previamente declarado la libreria time, seguimos con este proceso para generar los números aleatorios, lo escrito se llama semilla
	
	// El número aleatorio entre los caracter 1 y 9
	// Ahora comprobaremos si estos números estan repetidos, es decir, si las casillas se encuentran ocupadas
	do{      
	      i = rand() % 3;          // número aleatorio se escribe con rand (), %3 significa que nos dara un número aleatorio entre 0 y 2
	      j = rand() % 3;   
		  k=0;                     // declaramos esto para que una vez terminado salga del bucle 
		  
		  if (c[i][j]=='x' || c[i][j]=='o'){  // en caso de cumplirse el if, significa casillas ocupadas
		  	k=1;
		  }                
		
	}while(k==1);
	
	c[i][j] = 'o';
	
	 
	
	
}


void tablero (char c[3][3])    // sera la encargada de pintar en cada momento el tablero 
{
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		if(j<2){                       // hacemos con if para que en el tres no imprima la raya vertical
		        printf(" %c |",c[i][j]);        
		}else{
			printf("%c",c[i][j]);
		}
	}
	if(i<2){                  // haremos esto para imprimir la raya horizontal, deja una rayita de menos por cada caracter
	       printf("\n---------\n");        
 }
}
printf("\n\n"); 
}
int victoria (char c[3][3]) // Es de tipo valor porqué nos devolvera un valor, dependiendo de quien a ganado o de si no ha ganado nadie
{
	if (c[0][0] == 'x' || c[0][0]=='o'){
		if(c[0][0] == c[0][1] && c[0][0] == c[0][2]){
			if(c[0][0]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
		}
		if(c[0][0] == c[1][0] && c[0][0] == c[2][0]){
			if(c[0][0]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
			
		}
	
	if (c[1][1] == 'x' || c[1][1] =='o'){
		if(c[1][1] == c[0][0] && c[1][1] == c[2][2]){
			if(c[1][1]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
		}
		if(c[1][1] == c[1][0] && c[1][1] == c[1][2]){
			if(c[1][1]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
			
		}
		if(c[1][1] == c[2][0] && c[1][1] == c[0][2]){
			if(c[1][1]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
		
	    }
	    if(c[1][1] == c[0][1] && c[1][1] == c[2][1]){
			if(c[1][1]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
			
	    }
    }
    if (c[2][2] == 'x' || c[2][2] == 'o'){
    	if(c[2][2] == c[2][0] && c[2][2] == c[2][1]){
    		
    		if(c[2][2]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
    		
		}
		if(c[2][2] == c[0][2] && c[2][2] == c[1][2]){
    		
    		if(c[2][2]== 'x'){
				return 0; // Ganador
			}else{
				return 1; // Perdido
			}
    		
		}
	}
	
	
  }
  return 2; // No pasa nada
}
