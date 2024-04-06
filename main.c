#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *nome;
  int idade;
} Estrutura;

int main(void) {

  FILE *arquivo;
  char dados;
  char *fNome = "arquivo.txt";

  Estrutura estrutura = {"João", 15};

  // Abre o arquivo para gravação; se ocorrer erro, o programa aborta
  if ((arquivo = fopen(fNome, "wb")) == NULL) {
      puts("Erro ao abrir o arquivo!");
      return 1;
  }else{
    printf("Arquivo aberto com sucesso!\n");
  }
  // Grava a struct no arquivo
  if (fwrite(&estrutura, sizeof(Estrutura), 1, arquivo) != 1) {
      puts("Erro ao gravar conteúdo no arquivo!");
      fclose(arquivo);
      return 1;
  }
  
  
  fclose(arquivo);
  puts("Arquivo gravado com sucesso!");

  // Abre o arquivo para leitura
  if ((arquivo = fopen(fNome, "rb")) == NULL) {
      puts("Erro ao abrir o arquivo!");
      return 1;
  }

  // Lê a struct do arquivo
  if (fread(&estrutura, sizeof(Estrutura), 1, arquivo) != 1) {
      puts("Erro ao ler conteúdo do arquivo!");
      fclose(arquivo);
      return 1;
  }

  fclose(arquivo);
  // Agora você pode usar os dados da struct
  printf("Nome: %s\nIdade: %u\n", estrutura.nome, estrutura.idade);

  return 0;
}