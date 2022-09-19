#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


// Assinatura das funções:
int menu_usuario();
int usuario_cadastro();
int usuario_vizualizar();
int usuario_pesquisar();
int usuario_editar();
int usuario_excluir();

//variaveis globais de usuario
char nome[50];
char email[50];
char telefone[20];


int modulo_usuario(){
    
    setlocale (LC_ALL, "portuguese");
    char opcao = '\0';

    do{
        menu_usuario();

        printf("Digite uma opção:\n");
        scanf("%c", &opcao);
        getchar();

        if (opcao != '0'){
            if (opcao == '1'){
                usuario_cadastro();
            }
            else if (opcao == '2'){
                usuario_vizualizar();
            }
            else if (opcao == '3'){
                usuario_pesquisar();
            }
            else if (opcao == '4'){
                usuario_editar();
            }
            else if (opcao == '5'){
                usuario_excluir();
            }
            
            else {
               printf("Opção não dessenvolvida ou inválida\n");
            }
            printf("Aperte enter para continuar\n");
            getchar();
        }
            
        
        if (opcao == '0'){
            printf("Voltando ao menu principal...\n");
        }

    }
    while (opcao != '0');
    return 0;
}



int usuario_cadastro(){

    //nome
    printf("Infome seu nome:\n");
    scanf("%[A-Z a-z]", nome);
    getchar();

    printf("Seu nome é esse?\n");
    printf("%s", nome);
    printf("\n\n\n");


    //email
    printf("Infome seu email:\n");
    scanf("%[A-Za-z0-9.,@-]", email);
    getchar();

    printf("Seu email é esse?\n");
    printf("%s", email);
    printf("\n\n\n");


    //telefone
    printf("Infome seu telefone:\n");
    scanf("%[0-9 +()-]", telefone);
    getchar();

    printf("Seu telefone é esse?\n");
    printf("%s", telefone);
    printf("\n\n\n");

    return 0;
}
int usuario_vizualizar(){

    printf("Seu nome é esse?\n");
    printf("%s", nome);
    printf("\n\n\n");


    printf("Seu email é esse?\n");
    printf("%s", email);
    printf("\n\n\n");


    printf("Seu telefone é esse?\n");
    printf("%s", telefone);
    printf("\n\n\n");

    return 0;
}
int usuario_pesquisar(){
    printf("Busca não disponível\n");

    return 0;
}

int usuario_editar(){
    //printf("Edição não disponível\n");

    char editar;
    printf("Digite o que deseja editar:\n\n");
    printf("\n"
        "Nome:\t\t 1\n"
        "Email:\t\t 2\n"
        "Telefone:\t 3\n");
    
    scanf("%[1-3]", &editar);   
    getchar();

    

    // Editar nome
    if (editar == '1'){
        char resp;
        do {

        printf("Seu atual nome é esse:\n");
        printf("%s", nome);
        printf("\n\n\n");
        
        printf("Infome seu novo nome:\n");
        scanf("%[A-Z a-z]", nome);
        getchar();


        printf("Seu nome é esse? (s para sim)\n");
        printf("%s", nome);
        printf("\n\n");

        scanf("%c", &resp);
        getchar();
        } while (resp != 's');
    }
    // Editar email
    else if (editar == '2'){

        printf("Seu atual email é esse:\n");
        printf("%s", email);
        printf("\n\n");

        printf("Infome seu novo email:\n");
        scanf("%[A-Za-z0-9.,@-]", email);
        getchar();

        printf("Seu email novo é esse?\n");
        printf("%s", email);
        printf("\n\n\n");
    }

    // Editar telefone
    else if (editar == '3'){
        printf("Seu atual telefone é esse:\n");
        printf("%s", telefone);
        printf("\n\n");

        printf("Infome seu novo telefone:\n");
        scanf("%[0-9 +()-]", telefone);
        getchar();

        printf("Seu novo telefone é esse?\n");
        printf("%s", telefone);
        printf("\n\n\n");
    }

    return 0;
}
int usuario_excluir(){
    printf("Exclusão não disponível\n");

    return 0;
}