#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <cctype>

int opcao = 0;

struct User{
	char username[15];
	char password[15];
};

bool TelaLogin(User& user){	
	char inputLogin[15];
	char inputSenha[15];
	
	printf("Digite seu login: ");
	scanf("%s", inputLogin);
	
	printf("Digite sua senha: ");
	scanf("%s", inputSenha);
	
	if(strcmp(inputLogin, user.username)== 0 && strcmp(inputSenha, user.password) == 0)
	   
	   return true;
	else
	   return false;
	   
}

void MostrarMenu(){
	printf("***********************\n");
	printf("***TRABALHO UNISANTA***\n");
	printf("***********************\n");
	
	printf("1 - CODIFICAR\n");
	printf("2 - DECODIFICAR\n");
	printf("3 - ALTERAR SENHA\n");
	printf("DIGITE A OPCAO DESEJADA\n");
	scanf("%d", &opcao);
	
	getchar();
}

void Codificar(){
	char frase[50];
     printf("digite a frase a ser codificada: ");
     scanf("%[^\n]%*c", frase);
     for (int i = 0; i<strlen(frase); i++){
     	if(isalpha(frase[i])){
     		frase [i]= (frase[i] - 'a'+3) % 26 +'a';
		 }
	 }
	 printf("A frase codificada e: %s\n", frase);
}

void Decodificar(){
	 char frase2[50];
	 printf("digite a frase a ser decodificada: ");
     scanf("%[^\n]%*c", frase2);
     for (int i = 0; i<strlen(frase2); i++){
     	if(isalpha(frase2[i])){
     		frase2 [i]= (frase2[i] - 'a'-3) % 26 +'a';
		 }
	 }
	 printf("A frase codificada e: %s\n", frase2);
}

void AlterarSenha(User& user){
	char novasenha[15];
	printf("Entrar com a nova senha: ");
	scanf("%s",novasenha);
	strcpy(user.password, novasenha);
	if (TelaLogin(user)) {
        printf("Senha alterada com sucesso!\n");
         
    } else {
        printf("Autenticação falhou com a nova senha!\n");
    }
     
	//caso for 1 - Sim
	//retornar ao menu principal
}

int main(){
	User user;	
	strcpy(user.username, "admin");
	strcpy(user.password, "senha");
	setlocale(LC_ALL,"");
	bool loginSucesso = TelaLogin(user);
	if (loginSucesso) {
	    MostrarMenu();
	} else {
	    printf("Login falhou.\n");
	    return 0;
	}
	switch(opcao)
	{
		case 1: // Codificar
		  Codificar();
		break;
		
		case 2: // decodificar
		  Decodificar();
		break;
		
		case 3: // senha
		 AlterarSenha(user);
		break;
	}
	getchar();
	
   return(0);
}
