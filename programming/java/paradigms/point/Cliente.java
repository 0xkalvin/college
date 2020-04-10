package coordenada;

import java.util.Scanner;

public class Cliente {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int x = 0;
		int y = 0;
		Ponto ponto1 = null;
		for (int i = 1; i <= 2; i++) {
			System.out.printf("Digite um valor inteiro para o ponto %dX : ", i);
			x = sc.nextInt();
			System.out.printf("Digite um valor inteiro para o ponto %dY : ", i);
			y = sc.nextInt();
			if (i == 2)
				break;
			ponto1 = new Ponto(x, y);
		}
		Ponto ponto2= new Ponto(x, y);

		System.out.println("A distancia entre os pontos é: " + ponto1.distance(ponto2));
		if(ponto1.isEquals(ponto2)) {
			System.out.println("Os pontos possuem a mesma coordenada.");
		} else {
			System.out.println("Os pontos possuem a mesma coordenada.");
		}
		sc.close();
	}

}
