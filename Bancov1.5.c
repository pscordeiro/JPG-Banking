#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i,j,sair_menu,origem, contacep,digito1,result1,result2,digito2,valor,flags; 
int icpf[12];

//prototipos
void logar();
void fordelay();
void tentativa_login();
void fechar();
void menu_funcionario();
void menu_cliente();
void nova_conta();
void atualizar_info();
void transac();
void ver_info();
void apagar_acc();
void listar_clientes();

struct data { 
  int dia,mes,ano; 
};

struct {
  char nome[60];
  char sobrenome[60];
  char cpf[12];
  char cep[12];
  int n_conta,rg,ncasa;
  double telefone;
  float quantidade;
  struct data data_nasc;
  struct data deposito;
  struct data saque;
}adicionar,atualizar,verificar,rem,transacao;

int main()
{
  //system("COLOR 03");
  system("cls");
  logar();
  return 0;
  
}

void logar(void)
{

  printf(R"EOF(                                                                                                    

                                                $$\                           $$\           
                                                $$ |                          \__|          
                                                $$ |       $$$$$$\   $$$$$$\  $$\ $$$$$$$\  
                                                $$ |      $$  __$$\ $$  __$$\ $$ |$$  __$$\ 
                                                $$ |      $$ /  $$ |$$ /  $$ |$$ |$$ |  $$ |
                                                $$ |      $$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |
                                                $$$$$$$$\ \$$$$$$  |\$$$$$$$ |$$ |$$ |  $$ |
                                                \________| \______/  \____$$ |\__|\__|  \__|
                                                                    $$\   $$ |              
                                                                    \$$$$$$  |              
                                                                    \______/               
                                                                                                                                                                                                       
  )EOF");

  char cpf_acesso[12], chave[50], pass_funcionario[50]="Opet", pass_cliente[50]="ClienteOpet", cpf_funcionario[12]="11394103930", cpf_cliente[12]="13057862977";
  int i=0;

  do
  {

    printf("\n\n\t\t\t\t\t\tDigite seu CPF de acesso: ");
    scanf("%s",cpf_acesso);

    if((strcmp(cpf_acesso,cpf_funcionario)==0) || (strcmp(cpf_acesso,cpf_cliente)==0))
    {
      flags=1;
    }
    else{
      printf("\n\t\t\t\t\t\tUsu%crio inexistente!!\n\n\t\t\t\t\t\t", 160);
      fordelay(100000000);
      tentativa_login();
      flags=0;
    }
  } while (flags==0);

  if(flags=1){

    printf("\n\t\t\t\t\t\tDigite a sua chave de seguran%ca para logar: ", 135);
    scanf("%s",chave);

    if((strcmp(chave,pass_funcionario)==0) && (strcmp(cpf_acesso,cpf_funcionario)==0))
    {
      printf("\n\t\t\t\t\t\tChave correta!\n\n\t\t\t\t\t\tCarregando");
      for(i=0;i<=6;i++)
      {
        fordelay(100000000);
        printf("..");
      }
      system("cls");
      menu_funcionario();
    }

    if((strcmp(chave,pass_cliente)==0) && (strcmp(cpf_acesso,cpf_cliente)==0))
    {
      printf("\n\t\t\t\t\t\tChave correta!\n\n\t\t\t\t\t\tCarregando");
      for(i=0;i<=6;i++)
      {
        fordelay(100000000);
        printf("..");
      }
      system("cls");
      menu_cliente();
    }

    else
    {
      printf("\n\t\t\t\t\t\tChave Incorreta!!!\a");
      tentativa_login();
    }

  }
  
}

void tentativa_login(void)
{
  printf("\n\t\t\t\t\t\tDigite 1 para tentar novamente ou 0 para sair: ");
  scanf("%d", &sair_menu);
  

  if(sair_menu==1)
  {
    system("cls");
    logar();
  }
  else if(sair_menu==0)
  {
    system("cls");
    fechar();
  }
  else
  {
    printf("\n\t\t\t\t\t\tInv%clido!!",160);
    fordelay(100000000);
    printf("..");
    system("cls");
    tentativa_login();
  }

}

void menu_funcionario()
{
  int escolha;
  system("cls");
  printf(R"EOF(

                                          $$$$$\ $$$$$$$\   $$$$$$\        $$$$$$$\   $$$$$$\  $$\   $$\ $$\   $$\ $$$$$$\ $$\   $$\  $$$$$$\  
                                          \__$$ |$$  __$$\ $$  __$$\       $$  __$$\ $$  __$$\ $$$\  $$ |$$ | $$  |\_$$  _|$$$\  $$ |$$  __$$\ 
                                             $$ |$$ |  $$ |$$ /  \__|      $$ |  $$ |$$ /  $$ |$$$$\ $$ |$$ |$$  /   $$ |  $$$$\ $$ |$$ /  \__|
                                             $$ |$$$$$$$  |$$ |$$$$\       $$$$$$$\ |$$$$$$$$ |$$ $$\$$ |$$$$$  /    $$ |  $$ $$\$$ |$$ |$$$$\ 
                                       $$\   $$ |$$  ____/ $$ |\_$$ |      $$  __$$\ $$  __$$ |$$ \$$$$ |$$  $$<     $$ |  $$ \$$$$ |$$ |\_$$ |
                                       $$ |  $$ |$$ |      $$ |  $$ |      $$ |  $$ |$$ |  $$ |$$ |\$$$ |$$ |\$$\    $$ |  $$ |\$$$ |$$ |  $$ |
                                       \$$$$$$  |$$ |      \$$$$$$  |      $$$$$$$  |$$ |  $$ |$$ | \$$ |$$ | \$$\ $$$$$$\ $$ | \$$ |\$$$$$$  |
                                        \______/ \__|       \______/       \_______/ \__|  \__|\__|  \__|\__|  \__|\______|\__|  \__| \______/ 
                                                                                                                                               
                                                                              BEM VINDO AO MENU DE FUNCION%cRIO                                                                                                               
                                                                                             
  )EOF", 181);
  
  printf("\n\n\t\t\t\t\t\t1.Criar nova conta\n\t\t\t\t\t\t2.Atualizar informa%c%ces de uma conta existente\n\t\t\t\t\t\t3.Transa%c%ces\n\t\t\t\t\t\t4.Verificar detalhes de uma conta existente\n\t\t\t\t\t\t5.Deletar conta existente\n\t\t\t\t\t\t6.Ver lista de clientes\n\t\t\t\t\t\t7.Sair\n\n\t\t\t\t\t\tDigite sua escolha: ", 135,228,135,228);
  scanf("%d", &escolha);

  system("cls");

  switch(escolha)
  {
    case 1:nova_conta();
    break;
    case 2:atualizar_info();
    origem=0;
    break;
    case 3:transac();
    origem=0;
    break;
    case 4:ver_info();
    origem=0;
    break;
    case 5:apagar_acc();
    break;
    case 6:listar_clientes();
    break;
    case 7:fechar();
    break;
    default:
    printf("\n\n\t\t\t\t\t\tOp%c%co Inv%clida!!\n\t\t\t\t\t\tTente novamente !!\n\t\t\t\t\t\t", 135,198,160);
    system("pause");
    menu_funcionario();
  }

}

void menu_cliente()
{
  int escolha;
  system("cls");
  printf(R"EOF(

                                          $$$$$\ $$$$$$$\   $$$$$$\        $$$$$$$\   $$$$$$\  $$\   $$\ $$\   $$\ $$$$$$\ $$\   $$\  $$$$$$\  
                                          \__$$ |$$  __$$\ $$  __$$\       $$  __$$\ $$  __$$\ $$$\  $$ |$$ | $$  |\_$$  _|$$$\  $$ |$$  __$$\ 
                                             $$ |$$ |  $$ |$$ /  \__|      $$ |  $$ |$$ /  $$ |$$$$\ $$ |$$ |$$  /   $$ |  $$$$\ $$ |$$ /  \__|
                                             $$ |$$$$$$$  |$$ |$$$$\       $$$$$$$\ |$$$$$$$$ |$$ $$\$$ |$$$$$  /    $$ |  $$ $$\$$ |$$ |$$$$\ 
                                       $$\   $$ |$$  ____/ $$ |\_$$ |      $$  __$$\ $$  __$$ |$$ \$$$$ |$$  $$<     $$ |  $$ \$$$$ |$$ |\_$$ |
                                       $$ |  $$ |$$ |      $$ |  $$ |      $$ |  $$ |$$ |  $$ |$$ |\$$$ |$$ |\$$\    $$ |  $$ |\$$$ |$$ |  $$ |
                                       \$$$$$$  |$$ |      \$$$$$$  |      $$$$$$$  |$$ |  $$ |$$ | \$$ |$$ | \$$\ $$$$$$\ $$ | \$$ |\$$$$$$  |
                                        \______/ \__|       \______/       \_______/ \__|  \__|\__|  \__|\__|  \__|\______|\__|  \__| \______/ 
                                                                                                                                               
                                                                              BEM VINDO AO MENU DE CLIENTE                                                                                                               
                                                                                             
  )EOF");
  
  printf("\n\n\t\t\t\t\t\t1.Verificar detalhes da conta\n\t\t\t\t\t\t2.Transa%c%ces\n\t\t\t\t\t\t3.Sair\n\n\t\t\t\t\t\tDigite sua escolha: ", 135,228);
  scanf("%d", &escolha);

  switch(escolha)
  {
    case 1:origem=1;
    ver_info();
    break;
    case 2:origem=1;
    transac();
    break;
    case 3:fechar();
    break;
    default:
    printf("\n\t\t\t\t\t\tOp%c%co Inv%clida!!\n\t\t\t\t\t\tTente novamente !!",135,198,160);
    fordelay(100000000);
    menu_cliente();
  }
 
}

void nova_conta() 
{
  system("cls");

  printf(R"EOF(

                                      $$\   $$\                                       $$$$$$\                        $$\               
                                      $$$\  $$ |                                     $$  __$$\                       $$ |              
                                      $$$$\ $$ | $$$$$$\  $$\    $$\  $$$$$$\        $$ /  \__| $$$$$$\  $$$$$$$\  $$$$$$\    $$$$$$\  
                                      $$ $$\$$ |$$  __$$\ \$$\  $$  | \____$$\       $$ |      $$  __$$\ $$  __$$\ \_$$  _|   \____$$\ 
                                      $$ \$$$$ |$$ /  $$ | \$$\$$  /  $$$$$$$ |      $$ |      $$ /  $$ |$$ |  $$ |  $$ |     $$$$$$$ |
                                      $$ |\$$$ |$$ |  $$ |  \$$$  /  $$  __$$ |      $$ |  $$\ $$ |  $$ |$$ |  $$ |  $$ |$$\ $$  __$$ |
                                      $$ | \$$ |\$$$$$$  |   \$  /   \$$$$$$$ |      \$$$$$$  |\$$$$$$  |$$ |  $$ |  \$$$$  |\$$$$$$$ |
                                      \__|  \__| \______/     \_/     \_______|       \______/  \______/ \__|  \__|   \____/  \_______|

  
  )EOF");

  printf("\n\n\n\t\t\t\t\t\tDigite 1 para prosseguir e criar uma nova conta ou 2 para retornar ao menu: ");
  scanf("%d",&sair_menu);

  if (sair_menu==1) {
    //int escolha;  
    FILE *ptr;
    ptr=fopen("Registro.dat","a+");
      n_conta:
      system("cls");
      printf("\n\n\t\t\t\t\t\tAdicionando Registro");

      time_t now;

      time(&now);

      struct tm *local = localtime(&now);
      
      adicionar.deposito.dia = local->tm_mday;			
      adicionar.deposito.mes = local->tm_mon + 1;   	
      adicionar.deposito.ano = local->tm_year + 1900;	
      
      printf("\n\n\t\t\t\t\t\tHoje %c dia : %d/%d/%d\n", 130, adicionar.deposito.dia, adicionar.deposito.mes, adicionar.deposito.ano);

      printf("\n\t\t\t\t\t\tDigite o n%cmero da conta: ",163);
      scanf("%d",&verificar.n_conta);
      while(fscanf(ptr,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,&adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,&adicionar.quantidade,&adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF)
      {
        if (verificar.n_conta==adicionar.n_conta){
          printf("\n\t\t\t\t\t\tN%cmero da conta j%c foi utilizado", 163,160);
          fordelay(1000000000);
          printf("..");
          nova_conta();
        }
      }
      adicionar.n_conta=verificar.n_conta;
      printf("\n\t\t\t\t\t\tDigite seu nome e %cltimo sobrenome ex: (Paulo Cordeiro): ",163);
      scanf("%s%s",adicionar.nome,adicionar.sobrenome);
      printf("\n\t\t\t\t\t\tDigite sua data de nascimento (dd/mm/aaa): ");
      scanf("%d/%d/%d",&adicionar.data_nasc.dia,&adicionar.data_nasc.mes,&adicionar.data_nasc.ano);
      printf("\n\t\t\t\t\t\tDigite seu RG (apenas n%cmeros): ", 163);
      scanf("%d",&adicionar.rg);

      do
      {
        printf("\n\t\t\t\t\t\tDigite seu CEP ex: (88405-666): ");
        scanf("%s",adicionar.cep);
        contacep = strlen(adicionar.cep);

        if (contacep != 9) {
          printf("\n\t\t\t\t\t\tN%cmero de caracteres do CEP inv%clido\n\t\t\t\t\t\tTente Novamente\n", 163, 160);
          fordelay(1000000000);
          flags = 0;
        }
        else
        {
          flags = 1;
        }
      } while (flags==0);

      printf("\n\t\t\t\t\t\tDigite o n%cmero da sua casa: ", 163);
      scanf("%d",&adicionar.ncasa);

      do
      {
        int somador = 0;

        printf("\n\t\t\t\t\t\tDigite o seu CPF: ");
        scanf("%s", adicionar.cpf);

        if(strlen(adicionar.cpf) != 11) {
          printf("\n\t\t\t\t\t\tN%cmero de digitos inv%clido", 163,160);
          flags=0;
        }
        else if((strcmp(adicionar.cpf,"00000000000") == 0) || (strcmp(adicionar.cpf,"11111111111") == 0) || (strcmp(adicionar.cpf,"22222222222") == 0) ||
                (strcmp(adicionar.cpf,"33333333333") == 0) || (strcmp(adicionar.cpf,"44444444444") == 0) || (strcmp(adicionar.cpf,"55555555555") == 0) ||
                (strcmp(adicionar.cpf,"66666666666") == 0) || (strcmp(adicionar.cpf,"77777777777") == 0) || (strcmp(adicionar.cpf,"88888888888") == 0) ||
                (strcmp(adicionar.cpf,"99999999999") == 0)) {
          printf("\n\t\t\t\t\t\tInv%clido!! Os digitos do CPF n%co podem ser todos iguais", 160,198);
          flags=0;
            ///se o CPF tiver todos os números iguais ele é inválido.
        }
        else {

          for(i=0;i<11;i++)  
          {  
            icpf[i]=adicionar.cpf[i]-48;  
          }

        //Primeiro Digito 
          
          for(i=0;i<9;i++)  
          {  
            somador+=icpf[i]*(10-i);  
          }  
            
          result1=somador%11;  
            
          if( (result1==0) || (result1==1) )  
          {  
            digito1=0;  
          }  
            
          else  
          {  
            digito1 = 11-result1;  
          }  
            
        //Segundo Digito
          
          somador=0;  
            
          for(i=0;i<10;i++)  
          {  
            somador+=icpf[i]*(11-i);  
          }  
            
          valor=(somador/11)*11;  
          result2=somador-valor;  
            
          if( (result2==0) || (result2==1) )  
          {  
            digito2=0;  
          }  
            
          else  
          {  
            digito2=11-result2;  
          }  

          if((digito1==icpf[9]) && (digito2==icpf[10]))  
          {  
            flags=1;
          }  
          else  
          {  
            printf("\n\t\t\t\t\t\tCPF inv%clido", 160);
            flags=0;
          }
        }

        } while (flags==0);

      printf("\n\t\t\t\t\t\tDigite seu telefone com DDD (Ex: 41997226477): ");
      scanf("%lf",&adicionar.telefone);
      printf("\n\t\t\t\t\t\tDigite a quantidade que deseja como dep%csito inicial:R$", 162);
      scanf("%f",&adicionar.quantidade);

      adicionar.deposito.dia = local->tm_mday;			
      adicionar.deposito.mes = local->tm_mon + 1;   	
      adicionar.deposito.ano = local->tm_year + 1900;	

      fprintf(ptr,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);

      fclose(ptr);
      printf("\n\t\t\t\t\t\tConta criada com sucesso!!\n\n\t\t\t\t\t\t");
      system("pause");
      nova_conta();

  }

  if ((sair_menu==2) && (origem==0)) {
    system("cls");
    menu_funcionario();
  }
  else if((sair_menu==2) && (origem==1)) {
    system("cls"); 
    menu_cliente();
  }
  else 
  {
    printf("\n\t\t\t\t\t\tOp%c%co Inv%clida!\n\t\t\t\t\t\t",135,198,160);
    system("pause");
    nova_conta();
  }

}

void atualizar_info()
{
  system("cls");
  int escolha,teste=0;
  printf(R"EOF(

                          
                              $$$$$$\    $$\                         $$\ $$\                                     $$\            $$$$$$\            
                             $$  __$$\   $$ |                        $$ |\__|                                    \__|          $$  __$$\           
                             $$ /  $$ |$$$$$$\   $$\   $$\  $$$$$$\  $$ |$$\ $$$$$$$$\  $$$$$$\   $$$$$$\        $$\ $$$$$$$\  $$ /  \__| $$$$$$\  
                             $$$$$$$$ |\_$$  _|  $$ |  $$ | \____$$\ $$ |$$ |\____$$  | \____$$\ $$  __$$\       $$ |$$  __$$\ $$$$\     $$  __$$\ 
                             $$  __$$ |  $$ |    $$ |  $$ | $$$$$$$ |$$ |$$ |  $$$$ _/  $$$$$$$ |$$ |  \__|      $$ |$$ |  $$ |$$  _|    $$ /  $$ |
                             $$ |  $$ |  $$ |$$\ $$ |  $$ |$$  __$$ |$$ |$$ | $$  _/   $$  __$$ |$$ |            $$ |$$ |  $$ |$$ |      $$ |  $$ |
                             $$ |  $$ |  \$$$$  |\$$$$$$  |\$$$$$$$ |$$ |$$ |$$$$$$$$\ \$$$$$$$ |$$ |            $$ |$$ |  $$ |$$ |      \$$$$$$  |
                             \__|  \__|   \____/  \______/  \_______|\__|\__|\________| \_______|\__|            \__|\__|  \__|\__|       \______/ 
        

)EOF");

  printf("\n\n\n\t\t\t\t\t\tDigite 1 para atualizar uma informa%c%co ou 2 para retornar ao menu: ", 135,198);
  scanf("%d",&sair_menu);

  if (sair_menu==1)
  {
    int flags;
    FILE *antigo, *novo_reg;
    antigo=fopen("Registro.dat", "r");
    novo_reg=fopen("Novo.dat", "w");

    printf("\n\t\t\t\t\t\tDigite o n%cmero da conta do cliente que voc%c deseja alterar as informa%c%ces: ",163,136,135,198);
    scanf("%d",&atualizar.n_conta);

    while(fscanf(antigo,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,&adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,&adicionar.quantidade,&adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF)
    {
      if (adicionar.n_conta==atualizar.n_conta)
      {
        teste=1;
        printf("\n\t\t\t\t\t\tQual informa%c%co voc%c deseja alterar?\n\t\t\t\t\t\t1.CEP\n\t\t\t\t\t\t2.Telefone\n\t\t\t\t\t\t3.N%cmero da casa\n\t\t\t\t\t\t\n\t\t\t\t\t\tDigite sua escolha(1 para CEP, 2 para telefone ou 3 para n%cmero da casa): ", 135,198,136,163,163);
        scanf("%d", &escolha);
        //system("cls");
        
        if(escolha==1)
        {

          do
          {
            printf("\n\t\t\t\t\t\tDigite o novo CEP ex: (83410-567): ");
            scanf("%s", atualizar.cep);

            contacep = strlen(atualizar.cep);

            if (contacep != 9) {
              printf("\n\t\t\t\t\t\tN%cmero de caracteres do CEP inv%clido\n\t\t\t\t\t\tTente Novamente\n", 163, 160);
              fordelay(1000000000);
              flags = 0;
            }
            else
            {
              flags = 1;
            }
          } while (flags==0);

          fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,atualizar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);
          //system("cls");
          printf("\n\t\t\t\t\t\tAltera%c%ces salvas com sucesso!!\n\t\t\t\t\t\t", 135,228);
        }

        else if(escolha==2)
        {
          printf("\n\t\t\t\t\t\tDigite o novo telefone: ");
          scanf("%lf", &atualizar.telefone);
          fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,atualizar.telefone,adicionar.quantidade,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);
          //system("cls");
          printf("\n\t\t\t\t\t\tAltera%c%ces salvas com sucesso!!\n\n\t\t\t\t\t\t", 135,228);
        }

        else if(escolha==3)
        {
          printf("\n\t\t\t\t\t\tDigite o novo n%cmero da casa: ", 163);
          scanf("%d", &atualizar.ncasa);
          fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,atualizar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);
          //system("cls");
          printf("\n\t\t\t\t\t\tAltera%c%ces salvas com sucesso!!\n\n\t\t\t\t\t\t", 135,228);
        }   
        else 
        {
          printf("\n\t\t\t\t\t\tOp%c%co Inv%clida\n\n\t\t\t\t\t\t",135,198,160);
          system("pause");
          atualizar_info;
        }

      } //fecha o primeiro if
      
      //para caso n exista uma conta com esse número
      else {
        fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);
      }

    } //fecha o while

    fclose(antigo);
    fclose(novo_reg);
    remove("Registro.dat");
    rename("Novo.dat","Registro.dat");

    if(teste!=1)
    {  
      system("cls");
      printf("\n\t\t\t\t\t\tRegistro n%co encontrado!!\n\t\t\t\t\t\t", 198);
      system("pause");
      atualizar_info();
    }

    else
    {
      system("pause");
      atualizar_info();
    }
    
  }

  if ((sair_menu==2) && (origem==0)) {
    system("cls");
    menu_funcionario();
  }
  else if((sair_menu==2) && (origem==1)) {
    system("cls");
    menu_cliente();
  }
  else
  {
    printf("\n\t\t\t\t\t\tOp%c%co Inv%clida!\n\t\t\t\t\t\t",135,198,160);
    system("pause");
    atualizar_info();
  }

}

void transac()
{
  system("cls");

  printf(R"EOF(                                                                                                    
                                                                                                      $$$\ $$\ 
                                                                                                     $$ $$\$$ |
                                                                                                     $$ \$$$  |
                                $$$$$$$$\                                                            \__|\___/                                 
                                \__$$  __|                                                                                            
                                  $$ |    $$$$$$\   $$$$$$\  $$$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$\   $$$$$$$\  
                                  $$ |   $$  __$$\  \____$$\ $$  __$$\ $$  _____| \____$$\ $$  _____|$$  __$$\ $$  __$$\ $$  _____| 
                                  $$ |   $$ |  \__| $$$$$$$ |$$ |  $$ |\$$$$$$\   $$$$$$$ |$$ /      $$ /  $$ |$$$$$$$$ |\$$$$$$\   
                                  $$ |   $$ |      $$  __$$ |$$ |  $$ | \____$$\ $$  __$$ |$$ |      $$ |  $$ |$$   ____| \____$$\  
                                  $$ |   $$ |      \$$$$$$$ |$$ |  $$ |$$$$$$$  |\$$$$$$$ |\$$$$$$$\ \$$$$$$  |\$$$$$$$\ $$$$$$$  | 
                                  \__|   \__|       \_______|\__|  \__|\_______/  \_______| \_______| \______/  \_______|\_______/  
                                                                                                                                                                                                            
  )EOF");
  
  printf("\n\n\n\t\t\t\t\t\tDigite 1 para realizar uma transa%c%co ou 2 para retornar ao menu: ", 135,198);
  scanf("%d",&sair_menu);

  if (sair_menu==1)
  {
    int escolha,teste=0;
    FILE *antigo,*novo_reg;
    antigo=fopen("Registro.dat","r");
    novo_reg=fopen("Novo.dat","w");

    printf("\n\t\t\t\t\t\tDigite o n%cmero da conta em que vai fazer as opera%c%ces: ", 163,135,228);
    scanf("%d",&transacao.n_conta);

    while(fscanf(antigo,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,&adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,&adicionar.quantidade,&adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF)
    {

      if(adicionar.n_conta==transacao.n_conta) {
        
        teste=1;
        printf("\n\t\t\t\t\t\tVoc%c deseja realizar:\n\t\t\t\t\t\t1.Dep%csito\n\t\t\t\t\t\t2.Saque\n\n\t\t\t\t\t\tDigite a sua escolha (1 para deposito e 2 para saque): ", 136, 162);
        scanf("%d",&escolha);

        if (escolha==1)
          {
            printf("\n\t\t\t\t\t\tDigite a quantia que deseja depositar:R$ ");
            scanf("%f",&transacao.quantidade);
            adicionar.quantidade+=transacao.quantidade;
            
            fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,
            adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,
            adicionar.deposito.mes,adicionar.deposito.ano);
            printf("\n\n\t\t\t\t\t\tDep%csito realizado com sucesso!!\n\n\t\t\t\t\t\t", 162);
          }
          else if(escolha == 2)
          {
              printf("\n\t\t\t\t\t\tDigite a quantia que deseja sacar:R$ ");
              scanf("%f",&transacao.quantidade);
              adicionar.quantidade-=transacao.quantidade;
              fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,
              adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,
              adicionar.deposito.mes,adicionar.deposito.ano);
            
              printf("\n\n\t\t\t\t\t\tSaque feito com sucesso!!\n\n\t\t\t\t\t\t");
          }
          else
          {
            printf("\n\t\t\t\t\t\tOp%c%co Inválida",135,198);
            fordelay(1000000000);
            system("cls");
            transac();
          }
          
      }  
      
      else
      {
        fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,
        adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,
        adicionar.deposito.mes,adicionar.deposito.ano);
      }

    }

    fclose(antigo);
    fclose(novo_reg);
    remove("Registro.dat");
    rename("Novo.dat","Registro.dat");

    if(teste!=1)
    {
      printf("\n\n\t\t\t\t\t\tRegistro n%co encontrado\n\t\t\t\t\t\t", 198);
      //system("pause");
      //transac();
    }

    else
    {
      system("pause");
      transac();
    }

  }

  if ((sair_menu==2) && (origem==0)) {
    system("cls");
    menu_funcionario();
  }
  else if((sair_menu==2) && (origem==1)) {
    system("cls");
    menu_cliente();
  }
  else
  {
    printf("\n\t\t\t\t\t\tOp%c%co Inv%clida!\n\t\t\t\t\t\t",135,198,160);
    system("pause");
    transac();
  }

}

void ver_info()
{
  system("cls");
  printf(R"EOF(
                                                 $$\    $$\                           $$$$$$\            $$$$$$\            
                                                 $$ |   $$ |                          \_$$  _|          $$  __$$\           
                                                 $$ |   $$ | $$$$$$\   $$$$$$\          $$ |  $$$$$$$\  $$ /  \__| $$$$$$\  
                                                 \$$\  $$  |$$  __$$\ $$  __$$\         $$ |  $$  __$$\ $$$$\     $$  __$$\ 
                                                  \$$\$$  / $$$$$$$$ |$$ |  \__|        $$ |  $$ |  $$ |$$  _|    $$ /  $$ |
                                                   \$$$  /  $$   ____|$$ |              $$ |  $$ |  $$ |$$ |      $$ |  $$ |
                                                    \$  /   \$$$$$$$\ $$ |            $$$$$$\ $$ |  $$ |$$ |      \$$$$$$  |
                                                     \_/     \_______|\__|            \______|\__|  \__|\__|       \______/ 
                                                                                
  )EOF");

  printf("\n\n\n\t\t\t\t\t\tDigite 1 para ver informa%c%ces de uma conta ou 2 para retornar ao menu: ", 135,228);
  scanf("%d",&sair_menu);

  if (sair_menu==1)
  {
    FILE *ptr;
    int teste=0;
    int escolha;

    ptr=fopen("Registro.dat","r");
    printf("\n\t\t\t\t\t\tVoc%c gostaria de verificar pelo:\n\n\t\t\t\t\t\t1.N%cmero da conta\n\t\t\t\t\t\t2.Nome\n\n\t\t\t\t\t\tDigite sua escolha: ", 136,163);
    scanf("%d",&escolha);

    if (escolha==1){

      printf("\n\t\t\t\t\t\tDigite o n%cmero da conta: ", 163);
      scanf("%d",&verificar.n_conta);
    
      while (fscanf(ptr,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,
      &adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,
      &adicionar.quantidade,&adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF) {
 
        if(adicionar.n_conta==verificar.n_conta) {   
          system("cls");
          teste=1;

          printf("\n\t\t\t\t\t\tN%cmero da conta:%d\n\t\t\t\t\t\tNome:%s\n\t\t\t\t\t\tSobrenome:%s \n\t\t\t\t\t\tData de Nascimento:%d/%d/%d \n\t\t\t\t\t\tRG:%d \n\t\t\t\t\t\tCEP:%s \n\t\t\t\t\t\tN.Casa:%d\n\t\t\t\t\t\tCPF:%s \n\t\t\t\t\t\tTelefone:%.0lf\n\t\t\t\t\t\tSaldo da Conta:R$ %.2f\n\t\t\t\t\t\tData da cria%c%co da conta:%d/%d/%d\n\t\t\t\t\t\t\n\t\t\t\t\t\t", 163, adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,
          adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,135,198,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);

          system("pause");

        }
      }
    }

    else if (escolha==2){

      printf("\n\t\t\t\t\t\tDigite o nome: ");
      scanf("%s", verificar.nome);

      while (fscanf(ptr,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,
      &adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,&adicionar.quantidade,
      &adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF) {
        
        if(strcmp(adicionar.nome,verificar.nome)==0){
          system("cls");
          teste=1;

          printf("\n\t\t\t\t\t\tN%cmero da conta.:%d\n\t\t\t\t\t\tNome:%s\n\t\t\t\t\t\tSobrenome:%s \n\t\t\t\t\t\tData de Nascimento:%d/%d/%d \n\t\t\t\t\t\tRG:%d \n\t\t\t\t\t\tCEP:%s \n\t\t\t\t\t\tNCasa:%d\n\t\t\t\t\t\tCPF:%s \n\t\t\t\t\t\tTelefone:%.0lf\n\t\t\t\t\t\tQuantidade depositada:R$ %.2f\n\t\t\t\t\t\tData do deposito:%d/%d/%d\n\n\t\t\t\t\t\t",163,
          adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,
          adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);

          system("pause");

        }
      }
    }

    else
    {
      printf("\n\t\t\t\t\t\tOp%c%co Inv%clida", 135,160);
      fordelay(1000000000);
      ver_info();
    }
    
    fclose(ptr);

    if(teste!=1){

      //system("cls");
      printf("\n\t\t\t\t\t\tRegistro n%co encontrado!!\n\t\t\t\t\t\t", 198);
      system("pause");
      ver_info();
      }

    else {
      ver_info();
    }

    }
    
  else if ((sair_menu==2) && (origem==0)) {
    system("cls");
    menu_funcionario();
  }
  else if((sair_menu==2) && (origem==1)) {
    system("cls");
    menu_cliente();
  }
  else
  {
    printf("\n\t\t\t\t\t\tOp%c%co Inv%clida!",135,198,160);
    fordelay(100000000);
    ver_info();
  }

}

void apagar_acc()
{
  system("cls");
  printf(R"EOF(

    
                        $$$$$$\                                                           $$$$$$\                        $$\               
                      $$  __$$\                                                         $$  __$$\                       $$ |              
                      $$ /  $$ | $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\        $$ /  \__| $$$$$$\  $$$$$$$\  $$$$$$\    $$$$$$\  
                      $$$$$$$$ |$$  __$$\  \____$$\ $$  __$$\  \____$$\ $$  __$$\       $$ |      $$  __$$\ $$  __$$\ \_$$  _|   \____$$\ 
                      $$  __$$ |$$ /  $$ | $$$$$$$ |$$ /  $$ | $$$$$$$ |$$ |  \__|      $$ |      $$ /  $$ |$$ |  $$ |  $$ |     $$$$$$$ |
                      $$ |  $$ |$$ |  $$ |$$  __$$ |$$ |  $$ |$$  __$$ |$$ |            $$ |  $$\ $$ |  $$ |$$ |  $$ |  $$ |$$\ $$  __$$ |
                      $$ |  $$ |$$$$$$$  |\$$$$$$$ |\$$$$$$$ |\$$$$$$$ |$$ |            \$$$$$$  |\$$$$$$  |$$ |  $$ |  \$$$$  |\$$$$$$$ |
                      \__|  \__|$$  ____/  \_______| \____$$ | \_______|\__|             \______/  \______/ \__|  \__|   \____/  \_______|
                                $$ |                $$\   $$ |                                                                            
                                $$ |                \$$$$$$  |                                                                            
                                \__|                 \______/                                                                             

  )EOF");

  printf("\n\n\n\t\t\t\t\t\tDigite 1 para apagar uma conta ou 2 para retornar ao menu: ");
  scanf("%d",&sair_menu);

  if (sair_menu==1)
  {
    FILE *antigo,*novo_reg;
    int teste=0;
    antigo=fopen("Registro.dat","r");
    novo_reg=fopen("Novo.dat","w");

    printf("\n\t\t\t\t\t\tDigite o n%cmero da conta do cliente que voc%c deseja apagar: ",163,136);
    scanf("%d",&rem.n_conta);

    while (fscanf(antigo,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,
    &adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,&adicionar.quantidade,
    &adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF) {

      if(adicionar.n_conta!=rem.n_conta) {
        fprintf(novo_reg,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",adicionar.n_conta,adicionar.nome,adicionar.sobrenome,adicionar.data_nasc.dia,
        adicionar.data_nasc.mes,adicionar.data_nasc.ano,adicionar.rg,adicionar.cep,adicionar.ncasa,adicionar.cpf,adicionar.telefone,adicionar.quantidade,
        adicionar.deposito.dia,adicionar.deposito.mes,adicionar.deposito.ano);
      }
      
      else {
        teste++;
        printf("\n\t\t\t\t\t\tRegistro deletado com sucesso!\n\t\t\t\t\t\t");
      }
    }

    fclose(antigo);
    fclose(novo_reg);
    remove("Registro.dat");
    rename("Novo.dat","Registro.dat");


    if(teste==0)
    {
      printf("\n\t\t\t\t\t\tRegistro n%co encontrado!!\n\t\t\t\t\t\t", 198);
      system("pause");
      apagar_acc();
    }
    
    else {
      system("pause");
      apagar_acc();
    }
   
  }

  else if ((sair_menu==2) && (origem==0)) {
    system("cls");
    menu_funcionario();
  }
  else if((sair_menu==2) && (origem==1)) {
    system("cls");
    menu_cliente();
  }
  else
  {
    printf("\n\t\t\t\t\t\tOp%c%co Inv%clida!",135,198,160);
    fordelay(100000000);
    system("cls");
    apagar_acc();
  }

}

void listar_clientes()
{
  system("cls");

  printf(R"EOF(
          
             $$\       $$\             $$\                           $$\                           $$\ $$\                       $$\                         
             $$ |      \__|            $$ |                          $$ |                          $$ |\__|                      $$ |                        
             $$ |      $$\  $$$$$$$\ $$$$$$\    $$$$$$\         $$$$$$$ | $$$$$$\         $$$$$$$\ $$ |$$\  $$$$$$\  $$$$$$$\  $$$$$$\    $$$$$$\   $$$$$$$\ 
             $$ |      $$ |$$  _____|\_$$  _|   \____$$\       $$  __$$ |$$  __$$\       $$  _____|$$ |$$ |$$  __$$\ $$  __$$\ \_$$  _|  $$  __$$\ $$  _____|
             $$ |      $$ |\$$$$$$\    $$ |     $$$$$$$ |      $$ /  $$ |$$$$$$$$ |      $$ /      $$ |$$ |$$$$$$$$ |$$ |  $$ |  $$ |    $$$$$$$$ |\$$$$$$\  
             $$ |      $$ | \____$$\   $$ |$$\ $$  __$$ |      $$ |  $$ |$$   ____|      $$ |      $$ |$$ |$$   ____|$$ |  $$ |  $$ |$$\ $$   ____| \____$$\ 
             $$$$$$$$\ $$ |$$$$$$$  |  \$$$$  |\$$$$$$$ |      \$$$$$$$ |\$$$$$$$\       \$$$$$$$\ $$ |$$ |\$$$$$$$\ $$ |  $$ |  \$$$$  |\$$$$$$$\ $$$$$$$  |
             \________|\__|\_______/    \____/  \_______|       \_______| \_______|       \_______|\__|\__| \_______|\__|  \__|   \____/  \_______|\_______/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  )EOF");
  
  FILE *view;
  view=fopen("Registro.dat","r");
  int teste=0;
  printf("\n\t\t\t\tN.CONTA\t\tNOME\t\tSOBRENOME\t   CEP\t\t  TELEFONE\n");

  while (fscanf(view,"%d %s %s %d/%d/%d %d %s %d %s %lf %f %d/%d/%d\n",&adicionar.n_conta,adicionar.nome,adicionar.sobrenome,&adicionar.data_nasc.dia,
  &adicionar.data_nasc.mes,&adicionar.data_nasc.ano,&adicionar.rg,adicionar.cep,&adicionar.ncasa,adicionar.cpf,&adicionar.telefone,&adicionar.quantidade,
  &adicionar.deposito.dia,&adicionar.deposito.mes,&adicionar.deposito.ano)!=EOF) {

    printf("\n\t\t%20d\t%12s\t\t%8s\t%s\t%.0lf",adicionar.n_conta, adicionar.nome, adicionar.sobrenome, adicionar.cep, adicionar.telefone); 
    teste++;

  }

  fclose(view);

  if (teste==0)
  { 
    printf("\n\t\t\t\tSem Registros!!\n");
  }

  printf("\n\n\t\t\t\tDigite 1 para voltar ao menu ou 0 para sair: ");
  scanf("%d", &sair_menu);
  system("cls");

  if (sair_menu==1)
    menu_funcionario();
  else if(sair_menu==0)
    fechar();
  else
  {
    printf("\n\t\t\t\tOp%c%co Inv%clida!",135,198,160);
    fordelay(100000000);
    system("cls");
    listar_clientes();
  }
}

void fordelay(int j)
{   
  int i,k;
  for(i=0;i<j;i++)
  k=i;
}

void fechar()
{
  system("cls");
  printf("\n\n\n\n\n\t\t\t\t\t\tProjeto Integrador II - Sistema Banc%crio JPG\n\n\t\t\t\t\t\tDesenvolvido por Paulo Cordeiro / Jeferson Xavier / Guilherme Parra :)\n\n\n\a\n\t\t\t\t\t\t",160);
  system("pause");
  printf("\n\n\n\n");
  exit(0);

}

