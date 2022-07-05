#include <stdio.h>
//#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void usage(void){

    printf("\n\n\n\t Aqui é o passo a passo de como utilizar seu sistema\n");
    printf("\n\t 1° passo deve ser registrado o cliente com sua mesa e codigo utilizando (A)REGISTRAR CLIENTE\n");
    printf("\n\t Assim que registrado deve teclar em qualquer tecla, assim voltara para o menu\n");
    printf("\n\t Voltando para o menu é possivel mostrar quantas mesas temos sendo ocupadas no momento teclando (B)LISTAR\n");
    printf("\n\t É possivel também excluir o cadastro,\n\t isso será feito assim que o cliente estiver efetuado o pagamento\n\t utiliza-se (C)EXCLUIR CADASTRO\n");
    printf("\n\t Sendo assim também fica disponivel fazer alguma alteração no cadastro feito com (D)ALTERAR CADASTRO\n");
    printf("\n\t Assim que registrar o cliente se estiver nos conformes deve ser efetuado o pedido com (P)PEDIDO\n");
    printf("\n\t Na tela pedidos é onde é registrado o que o cliente deseja de acordo com o cardápio do estabelecimento\n");
    printf("\n\t Assim que registrado o pedido, ele é impresso em ordem direto à cozinha\n");
    getch();
}

// typedef Fila

// funcao para inserir pedido
//    perguntar o numero da mesa
//    achar o cliente na lista
//    perguntar qual produto
//    inserir no fim da fila

// funcao para imprimir pedido
//    pegar o primeiro pedido da fila
//     imprimir
//    retirar da fila


void cardapio(void){

        printf(">>>>>>> \t\tCardápio\t\t <<<<<<<\n\n");
        printf("\n\t >>>>>>>LANCHES<<<<<<<");
        printf("\n\t (1) X - Saladinha");
        printf("\n\t (2) X - Tudinho  ");
        printf("\n\t (3) X - Bacon    ");
        printf("\n\t (4) X - Magnetude");
        printf("\n\t (5) X - ShowDeBola");
        printf("\n\t (6) Hot-Dog\n\n");
        printf("\n\t >>>>>>>Bebidas<<<<<<<");
        printf("\n\t (7) Coca");
        printf("\n\t (8) Guarana antartica");
        printf("\n\t (9) Fanta laranja\n\n");
        printf("\n\t >>>>>Suco natural<<<<<");
        printf("\n\t (10) Laranja\n");
        printf("\n\t >>>>>Suco de polpa<<<<<");
        printf("\n\t (11) Abacaxi ");
        printf("\n\t (12) Morango");
        printf("\n\t (13) Acerola");
        printf("\n\t (14) Caju");
        printf("\n\t (15) Petit Gateau\n\n\n\t");
}

 typedef struct fila {
     char produto[40];
     char endereco[40];
     struct fila* prox;
   } Fila;

   //Declaração de funções.
   Fila *inserir_pedido(Fila* primeiro);
   Fila *retirar_pedido(Fila* primeiro);

   Fila *inserir_pedido(Fila *primeiro) {

    Fila pedido;
    Fila *atual= primeiro;
     char identificador= 'F';
     unsigned int produto;

     cardapio();

     //Lendo as informações do restaurante.
     printf("  Mesa: ",135);
     fflush (stdin); fgets(pedido.endereco, 40, stdin); printf ("\n");
     printf(" Produto : ",162);
     scanf("%u",&produto);printf ("\n");

            Fila* NovoPedido=(Fila*) malloc (sizeof(Fila));
         strcpy(NovoPedido->endereco, pedido.endereco);

         switch(produto) {
         case 1:
            strcpy(NovoPedido->produto, "X-Saladinha");
            break;
         case 2:
            strcpy(NovoPedido->produto, "X-Tudinho");
            break;
         case 3:
            strcpy(NovoPedido->produto, "X-Bacon");
            break;
        case 4:
            strcpy(NovoPedido->produto, "X-Magnetude");
            break;
        case 5:
            strcpy(NovoPedido->produto, "X-ShowDeBola");
            break;
        case 6:
            strcpy(NovoPedido->produto, "X-HotDog");
            break;
        case 7:
            strcpy(NovoPedido->produto, "Coca");
            break;
        case 8:
            strcpy(NovoPedido->produto, "Guarana Antartica");
            break;
        case 9:
            strcpy(NovoPedido->produto, "Fanta Laranja");
            break;
        case 10:
            strcpy(NovoPedido->produto, "Suco Laranja");
            break;
        case 11:
            strcpy(NovoPedido->produto, "Polpa Abacaxi");
            break;
        case 12:
            strcpy(NovoPedido->produto, "Polpa Morango");
            break;
        case 13:
            strcpy(NovoPedido->produto, "Polpa Acerola");
            break;
        case 14:
            strcpy(NovoPedido->produto, "Polpa Caju");
            break;
        case 15:
            strcpy(NovoPedido->produto, "Petit Gateau");
            break;

        }

    NovoPedido->prox = NULL;
    if (primeiro == NULL) {
                 printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");

     return NovoPedido;
    }

    while(atual->prox != NULL) atual = atual->prox;

    atual->prox = NovoPedido;

         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
    return primeiro;



   }


   Fila *retirar_pedido(Fila* primeiro) {
        if(primeiro == NULL) {
            printf("\t\tSem Pedidos...");
            return NULL;
        }

       printf("\n\n\t Mesa: %s\n", primeiro->endereco);
       printf("\n\n\tProduto: %s\n", primeiro->produto);

        primeiro = primeiro->prox;

        return primeiro;
   }

 typedef struct lista{
     char nome[40];
     char endereco[40];
     unsigned long int codigo;
     struct lista* prox;
   }Lista;

   //Declaração de funções.
   Lista* inserir_restaurantes(Lista* primeiro);
   void listar_restaurantes(Lista* primeiro);
   Lista* excluir_restaurantes(Lista* primeiro);
   void alterar_restaurantes(Lista* primeiro);


Lista* inserir_restaurantes (Lista *primeiro){
     Lista restaurante;
     Lista *atual= primeiro;
     char identificador= 'F';

     //Lendo as informações do restaurante.
     printf("  Nome: ");
     fflush (stdin); fgets(restaurante.nome, 40, stdin); printf ("\n");
     printf("  Mesa: ",135);
     fflush (stdin); fgets(restaurante.endereco, 40, stdin); printf ("\n");
     printf("  Codigo Cliente : ",162);
     scanf("%u",&restaurante.codigo);printf ("\n");

     //Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==restaurante.codigo){
            identificador= 'V';
            break;
        }
     }

     if(identificador!='V' && (strlen(restaurante.nome)!=1 && strlen(restaurante.endereco)!=1)){
         //Alocando os espaços e guardando as informações do restaurante.
         Lista* NovoRestaurante=(Lista*) malloc (sizeof(Lista));
         strcpy(NovoRestaurante->nome, restaurante.nome);
         strcpy(NovoRestaurante->endereco, restaurante.endereco);
         NovoRestaurante->codigo= restaurante.codigo;
         NovoRestaurante->prox= primeiro;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return NovoRestaurante;
     }else{
         printf("  Cadastro inv%clido.",160);
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return primeiro;
     }
}

void listar_restaurantes (Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.

     //Imprimindo os restaurantes da lista, e suas repectivas informações.
     for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nome: ");
        printf("%s", atual->nome);
        printf("\n  Mesa: ",135);
        printf("%s", atual->endereco);
        printf("\n  C%odigo: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum restaurante cadastrado.");
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_restaurantes(Lista *primeiro){

     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     unsigned long int codigo=0;

     //Requisitando e lendo o código do restaurante a ser excluído.
     printf("  C%cdigo do Cliente a ser exclu%cdo: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);

     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }

     //Mensagem caso o restaurante não seja encontrado.
     if(atual==NULL){
        printf("\n  Restaurante n%co encontrado.", 198);
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
     }

     //Excluindo o primeiro restaurante da lista.
     if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        primeiro= atual->prox;
     //Excluindo um restaurante do meio da lista.
     }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= atual->prox;
     }

     //Desalocando o espaço da memória.
     free(atual);
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     return primeiro;
}

//Função para alterar restaurantes.
void alterar_restaurantes(Lista* primeiro){
     char nome_substituto[40], endereco_substituto[40];
     unsigned long int codigo;
     Lista* atual=primeiro;

     //Requisitando e lendo o código do restaurante a ser alterado.
     printf("  C%cdigo do cliente a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);

     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }

     //Alterando os dados do restaurante.
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin);
        strcpy(atual->nome,nome_substituto);
        printf("\n  Nova Mesa: ",135);
        fflush (stdin); fgets(endereco_substituto, 40, stdin); printf ("\n");
        strcpy(atual->endereco,endereco_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  Restaurante n%co encontrado.",198);
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
main()
{
    setlocale(LC_ALL,"Portuguese");
   //Declaração de variáveis
   Lista *primeiro= NULL;
   Fila *pedidos = NULL;
   char opcao;

   //Artifício para repetir o programa.
   while(opcao!='s')
   {
     //Menu de opcoes
      printf("  ");printf("\n\n\t\t\t        LanchoNet'S ");printf("\t\t\t      \n");
      printf("\n\n\t\t\t >>>>>>>   MENU   ");printf("<<<<<<<\t\t\t\t      \n\n");
      printf("\n\t\t\t   <Q>  (Usage) Como Utilizar        \n");
      printf("\n\t\t\t   <A>  Novo Cliente                 \n");
      printf("\n\t\t\t   <B>  Listar                       \n");
      printf("\n\t\t\t   <C>  Excluir cadastro             \n");
      printf("\n\t\t\t   <D>  Alterar cadastro             \n");
      printf("\n\t\t\t   <P>  Pedido                       \n");
      printf("\n\t\t\t   <S>  Sair                         \n");

      //Lendo a opcao do menu
      fflush(stdin);
      opcao= getch();

      //Menu de opcoes
      switch(opcao)
      {
            case 'Q':
            case 'q':
            usage();
            printf("\033[H\033[J");
         break;

         case 'A':
         case 'a':
                         //Inserindo os clientes/mesas.
              fflush(stdin);
              printf("\033[H\033[J");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              primeiro= inserir_restaurantes(primeiro);
         getch();
         printf("\033[H\033[J");
         break;

         case 'B':
         case 'b':
              //Listando os restaurantes.
             printf("\033[H\033[J");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t     LISTA DE MESAS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              listar_restaurantes(primeiro);
         getch();
        printf("\033[H\033[J");
         break;

         case 'C':
         case 'c':
              //Excluindo restaurantes da lista.
             printf("\033[H\033[J");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              primeiro= excluir_restaurantes(primeiro);
         getch();
         printf("\033[H\033[J");
         break;

         case 'D':
         case 'd':
              //Alterando restaurantes da lista.
             printf("\033[H\033[J");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              alterar_restaurantes(primeiro);
         getch();
         printf("\033[H\033[J");
         break;

         case 'S':
         case 's':
              //Artifício para sair do programa.
              opcao='s';
         break;

          case 'P':
         case 'p':
              //Inserindo os pedidos.
              fflush(stdin);
         printf("\033[H\033[J");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        NOVO  PEDIDO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                pedidos = inserir_pedido(pedidos);
         getch();
         printf("\033[H\033[J");
         break;

         case 'I':
            case 'i':
            pedidos = retirar_pedido(pedidos);
            break;

         default:
              //Previnir a situação de um usuário digitar uma opcão inexistente no menu.
             printf("\033[H\033[J");
         break;
      }
   }
}
