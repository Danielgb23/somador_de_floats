/*  Somador de Floats
 *
 * Este programa recebera uma serie de caracteres representando floats na sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela a
 * soma desses numeros.
 */

#include <stdio.h>
#include <strings.h>
#define NUMER_MAX 50		//tamanho maximo da parte inteira

float converte_vetor(char * vetor_ascii){
	float num=0;
	int i=0, d = 1;
	while (vetor_ascii[i] != '\0')	//conta caracteres
		i++;

	i--;

	for(; i >= 0; i--){		//soma os caracteres menos 48 para converter em num
		num+=(vetor_ascii[i]-48)*d;
		d*=10;
	}

	return num;
}

int main() {
	char c=' ';		//comeca com espaco para caso haja um float logo no comeco
	char aux[NUMER_MAX];
	float numero=0, final=0, i=1;;
	int j;

	while (c != '\n') {

		if ( c ==' '){					//para não ter uma string grudada antes
			scanf("%c", &c);
			if ( c > 47 && c < 58 ){		//verifica se o caractere e numerico
				numero=0;
				aux[0] = '\0';
				while ( c > 47 && c < 58 ) {		//se for continua lendo ate chegar num caractere nao numerico
					strncat( aux, &c, 1);
					scanf("%c", &c);
				}
				numero+=converte_vetor(aux);

				if( c == '.' || c == ','  )	{	//se houver uma vigula ou ponto começa a ler a parte numero
					scanf("%c", &c);		//pula o ponto/virgula
					i = 0.1;			//reseta contador de decimos

					while ( c > 47 && c < 58 ){
						numero+= (c-48)*i;	//soma o algarismo na variavel 'decimal'
						scanf("%c", &c);

						i/=10;			//dimunui o peso do algarismo
					}
				}

				if (c == ' ' || c == '\n')		//para a string nao estar grudade em nada no final
					final+=numero;
			}	
		}
		else				//se logo depois do float houver ' ' pula para ver se ha outro float
			scanf("%c", &c);


	}



	sprintf(aux, "%f", final);				//coloca numero em string

	j=strlen(aux)-1;	

	while(aux[j] == '0'){					//le string ate o ponto	
		j--;	
	}
	if (aux[j] != '.')					//volta uma casa se não for o ponto
		j++;

	aux[j]='\0';						//encerra string

	printf("%s\n", aux);

	return 0;
}
