package br.ic.ufal;
import java.util.ArrayList;
import java.util.Random;



public class RedeNeural {
		int size = 0;
		int n = 0;
		static double coeficiente = 0.3;
		static double[][] pesos= {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
		static int linha = 5;
		static int coluna = 5;
		
	 /* public static double Soma(int entrada[][] ) {		  
		double soma = 0;
		for(int i = 0; i<linha; i++) {
			  for(int j = 0; j<coluna; j++) {
				  if(j!=1) {
					  soma = entrada[i][j]*pesos[i][j];
				  }				 
			  }			 
		}
		soma += entrada[1][1]*pesos[1][1];
		return soma;
	  }*/
		
	  /// checa existencia de retagulos 1x2
	  public static int FuncaoAtivacao2(int entrada[][]) {
		  double soma1 = (entrada[1][2]*pesos[1][2]) + (entrada[2][2]*pesos[2][2]);
		  double soma2 = (entrada[2][2]*pesos[2][3]) + (entrada[2][2]*pesos[2][2]);
		  
		//se acontecer existe pelo menos 1 retangulo 1x2
		  if ((soma1>0.255) || (soma2 > 0.255)) return 1;
		  
		  return 0;
	  }
	  
	// checa existencia de retagulos 2x4
	  public static int FuncaoAtivacao3(int entrada[][]) {
		  
		  // retangulo top right
		  double soma1 = (entrada[1][1]*pesos[1][1]) + (entrada[1][2]*pesos[1][2]) + (entrada[1][3]*pesos[1][3]) + (entrada[1][4]*pesos[1][4]) +
				  (entrada[2][1]*pesos[2][1]) + (entrada[2][2]*pesos[2][2]) + (entrada[2][3]*pesos[2][3]) + (entrada[2][4]*pesos[2][4]);
		// retangulo top left	
		
		  double soma2 = (entrada[1][0]*pesos[1][0]) + (entrada[1][1]*pesos[1][1]) + (entrada[1][2]*pesos[1][2]) + (entrada[1][3]*pesos[1][3]) +
				  (entrada[2][0]*pesos[2][0]) + (entrada[2][1]*pesos[2][1]) + (entrada[2][2]*pesos[2][2]) + (entrada[2][3]*pesos[2][3]);
		 
		  // retangulo down right
		  double soma3 = (entrada[2][1]*pesos[1][1]) + (entrada[2][2]*pesos[2][2]) + (entrada[2][3]*pesos[2][3]) + (entrada[2][4]*pesos[2][4]) +
				  (entrada[3][1]*pesos[3][1]) + (entrada[3][2]*pesos[3][2]) + (entrada[3][3]*pesos[3][3]) + (entrada[3][4]*pesos[3][4]);
		 
		  // retangulo down left
		  double soma4 = (entrada[2][0]*pesos[2][0]) + (entrada[2][2]*pesos[2][2]) + (entrada[2][3]*pesos[2][3]) + (entrada[2][3]*pesos[2][3]) +
				  (entrada[3][0]*pesos[3][0]) + (entrada[3][1]*pesos[3][1]) + (entrada[3][2]*pesos[3][2]) + (entrada[3][3]*pesos[3][3]);
		 
		 
		 if( (soma1>3)|| (soma2> 3)|| (soma3 > 3)|| (soma4> 3) ) {
			 
			 return 1;
		 }
		 
		  return 0;
	  }
	  
	  public static int FuncaoAtivacao(int entrada[][]) {
		  double retangulo1x2 = FuncaoAtivacao2(entrada) ;
		  double retangulo2x4 =  FuncaoAtivacao3(entrada) ;
		 // System.out.println(FuncaoAtivacao2(entrada));
		//  System.out.println(FuncaoAtivacao2(entrada));
		  
		  if  ((entrada[2][2]*pesos[2][2]) == 0 )
			  {
			 
			  
			  return 0;
			  }
		  else if ((retangulo1x2 > 0) || (retangulo2x4 >0)) {
			  
			   return 1;
		  }
			 
		 
		  
		  return 0 ; 
		 
	  }
	  public static void Aprendizagem (int entrada[][], int saida) {		  
		//  double soma = Soma(entrada);
		  int y = FuncaoAtivacao(entrada);
		 		  
				  while(y!= saida) {
					//  System.out.println(y);
					  for(int i = 0; i<linha; i++) {
						  for(int j = 0; j<coluna; j++) {
							    pesos[i][j] = pesos[i][j] + coeficiente*(saida-y)*entrada[i][j]; 
								//
								 // System.out.println("peso "+ pesos[i][j]);
							  }
						  }
					  y = FuncaoAtivacao(entrada);
					  }
					  //pesos[1][1] = pesos[1][1] + coeficiente*(saida-y)*entrada[1][1];	
					 // y = FuncaoAtivacao(entrada);
					  
					 
		 }	
				  //System.out.println("aqui 2");
	 
	  public static void testa (int entrada[][]) {
		  
		  if(FuncaoAtivacao2(entrada) == 1 && FuncaoAtivacao3(entrada)== 1) {
			  System.out.println("um retângulo 1x2 e um retangulo 2x4");
		}
		  else if (FuncaoAtivacao2(entrada) == 1 && FuncaoAtivacao3(entrada)== 0) {
			  System.out.println("um retangulo 1x2 e zero 2x4");
			  
		  }
			 
		  else if (FuncaoAtivacao2(entrada) == 0 && FuncaoAtivacao3(entrada)== 1) {
			  System.out.println("zero retangulo 1x2 e um retangulo 2x4");
		  }
		  else System.out.println("zero retangulos válidos");		  
	  }
	  
	  
	  public static void main(String[] args) {
		  Random gerador = new Random();
		  int count = 0;
		  for(int i = 0; i<linha; i++) {
			  for(int j = 0; j<coluna; j++) {
				   pesos[i][j] =  gerador.nextInt((1 - 0) + 1);
			  }		  
		  }
		  		  
		  
		  int [][] a = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
		  int [][] b = {{0, 0, 1, 0, 0},{0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 0}};
		  int [][] c = {{0, 0, 1, 0, 0},{0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}};
		  int [][] mtr = {{0, 0, 0, 0, 0},{0, 1, 1, 1, 1}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
		  int [][] mtl = {{0, 0, 0, 0, 0},{1, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
		  int [][] mdl = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {0, 0, 0, 0, 0}};
		  int [][] mdr = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 1, 1, 1, 1}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};
		  int [][] pr = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
		  int [][] pl = {{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
		  
		  Aprendizagem(a, 0);	
		  
		  Aprendizagem(mtr, 1);		
		  
		  Aprendizagem(mtl, 1);
		  
		  Aprendizagem(mdl, 1);
		  
		  Aprendizagem(mtr, 1);
		  
		  Aprendizagem(mdr, 1);	
		  
		  Aprendizagem(pr, 1);
		  
		  Aprendizagem(pl, 1);
		  Aprendizagem(b, 0);
		  
		  Aprendizagem(c, 0);
		  
		  
		  
		//  System.out.println("peso "+  FuncaoAtivacao2(m));
		  System.out.println(" teste"+ count ++);
		  testa(pl);
		  System.out.println(" teste"+ count ++);
		  testa(a);
		 
		  System.out.println(" teste"+ count ++);
		  testa(mtr);
		  System.out.println(" teste"+ count ++);
		  testa(mdl);
		  
		  		  System.out.println(" teste"+ count ++);
		  testa(mtl);
		  System.out.println(" teste"+ count ++);
		  testa(a);
		  System.out.println(" teste"+ count ++);
		  testa(c);  
	  }
}



