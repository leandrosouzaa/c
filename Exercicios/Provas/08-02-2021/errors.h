void internalError(const char* type, const char* message) {
   system("clear");
   printf("Desculpe, tivemos um ERRO INTERNO.\n\n");
   printf("Tipo: %s.\n", type);
   printf("Mensagem: %s.\n\n\n", message);
   exit(1);
}