/*  Somador de Floats
 *
 * Este programa recebera uma serie de caracteres representando floats na sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela a
 * soma desses numeros.
 */

#include <stdio.h>
#include <strings.h>
#define NUMER_MAX 10

float converte_vetor(char * vetor_ascii){
	float num=0;
	int i=0, d = 1;
	while (vetor_ascii[i] != '\0')
		i++;

	i--;

	for(; i >= 0; i--){
		num+=(vetor_ascii[i]-48)*d;
		d*=10;
	}

	return num;
}

int main() {
	char c;
	char aux[NUMER_MAX];
	float numero=0, i=1;;


	while (c != '\n') {
		scanf("%c", &c);

		if ( c > 47 && c < 58 ){			//verifica se o caractere e numerico
			aux[0] = '\0';
			while ( c > 47 && c < 58 ) {		//se for continua lendo ate chegar num caractere nao numerico
				strncat( aux, &c, 1);
				scanf("%c", &c);
			}
			numero+=converte_vetor(aux);

			if( c == '.' || c == ','  )	{	//se houver uma vigula ou ponto começa a ler a parte numero
				scanf("%c", &c);		//pula o ponto/virgula
				i = 0.1;			//reseta contador de decimos

				while ( c > 47 && c < 58 )
					scanf("%c", &c);

				numero+= (c-48)*i;	//soma o algarismo na variavel 'decimal'
				i/=10;			//dimunui o peso do algarismo
			}

		}	


	}



	printf("%f\n", numero);


	return 0;
}
