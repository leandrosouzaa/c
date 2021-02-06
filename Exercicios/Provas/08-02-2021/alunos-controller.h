Aluno create_aluno() {
   Aluno aluno = read_aluno();
   save_aluno(aluno);
   
   return aluno;
}