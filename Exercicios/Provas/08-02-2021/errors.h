void internalError(const char* type, const char* message) {
   system("cls");
   printf("Desculpe, tivemos um ERRO INTERNO.\n\n");
   printf("Tipo: %s.\n", type);
   printf("Mensagem: %s.\n\n\n", message);
   exit(1);
}

void simpleError(const char* message) {
   

   setbuf(stdin, NULL);
   getchar();
}