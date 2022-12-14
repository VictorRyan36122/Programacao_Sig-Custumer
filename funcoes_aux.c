#include <stdio.h>
#include <string.h>

#define True 1
#define False 0
typedef struct midia Midia;

void enter(void){
    char opcao;
    printf("Aperte enter para continuar\n");
    scanf("%c", &opcao);
    getchar();
}

int confirmacao(void){
    char resp;
    printf("\n");
    printf("Confirme se está correto (s para sim)...\n");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    
    if (resp == 's'){
        return True;
    }
    else{
        return False;
    }
}

char opcoes_pergunta(void){
    char opcoes;
    scanf("%[1-3]", &opcoes);
    printf("\n\n");
    getchar();
    return opcoes;
}


void vizualizar_lista(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(a[i] == ';'){
            printf("\n");
        } else{
            printf("%c",a[i]);
        }
        i++;
    }
}


// adaptado de NadjibSoft no vídeo https://www.youtube.com/watch?v=d_M9PqPpTFI&t=50s
int string_num(char a[]){
    int digit, j=1,number=0; // j=casa decimal

    for (int i = strlen(a)-1; i>=0; i-=1){
        digit = a[i];
        digit = digit -48;
        number = number+(digit *j);
        j *= 10;
    }
    return number;
}

int validar_num(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if((a[i] >= '0' ) && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}



int validar_cpf(char a[]){
    // printf("%s\n",a);
    // Parte 1, primeiro dígito verificador
    int b = 0, c = 0, d = 0, e =0, f=0, g=0;
    int num =10;
    int valido;

    for (int i = 0; i <=8; i+=1){
        a[i] = a[i]-48;
        // printf("a[i]%d\t",a[i]);
        // printf("%d",num);
        b += a[i] * num;
        num -= 1;
        // printf("b[i]=%d\n",b);
    }
    // printf("b=%d\n",b);
    c = b % 11;
    // printf("c=%d\n",c); // essencial
    if (c >= 10){
        c = 0;
        d = 0;
    }
    else if (c<=1){
        d=0;
    }
    else{
    d = 11 - c;
    }
    // printf("d=%d\n",d); // essencial

    // Parte 2, segundo dígito verificador
    num = 11;
    a[9]= a[9]-48;
    a[10]= a[10]-48;
    for (int i = 0; i <= 9; i+=1){
        //printf("a[i]%d\t",a[i]);
        //printf("%d",num);
        e += a[i] * num;
        // printf("e[i]=%d\n",e);
        num -= 1;
    }
    //printf("e=%d\n",e);

    f = e % 11;
    // printf("f=%d\n",f); // essencial
    if (f >= 10){
        f=0;
        g = 0;
    }
    else if(f<=1){
        g=0;
    }
    else{
        g = 11 - f;
    }
    // printf("g=%d\n",g); // essencial

    // parte 3, verificar se os dígitos verificadores estão certos
    if ((a[9] == d) && (a[10] == g)){
        valido = True;
    }
    else{
        valido = False;
    }
    return valido;
}


// usado em usuario.c
// Adaptado de Daynne github: https://github.com/DayXL ↓
int validar_nome(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em usuario.c
int validar_email(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= '@' ) && (a[i] <= 'z')) || (a[i] == '.')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em usuario.c
int validar_telefone(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if((a[i] >= '0' ) && (a[i] <= '9')){
            i += 1;
        } 
        else if ((a[i] == '(' ) || (a[i] <= ')') || (a[i] == ' ')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em redeSocial.c
int validar_twitterSteam(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= '@' ) && (a[i] <= 'z')) || (a[i] == '.')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em redeSocial.c
int validar_youtube(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}

// usado em interesse.c
int validar_nomeMidia(char a[]){
    int i;
    i = '\0';
    while (a[i] != '\0'){
        if(((a[i] >= 'a' ) && (a[i] <= 'z')) || (a[i] == ' ') || (a[i] == ';')){
            i += 1;
        } 
        else if ((a[i] >= 'A' ) && (a[i] <= 'Z')){
            i += 1;
        }
        else if ((a[i] >= '0') && (a[i] <= '9')){
            i += 1;
        }
        else if ((a[i] == '&') || (a[i] == '\'') || (a[i] == ':') || (a[i] == '.')){
            i += 1;
        }
        else{
            return False;
        }
    }
    return True;
}