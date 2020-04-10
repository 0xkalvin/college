package exercise;

import java.util.Scanner;

public class Client {

	public static void main(String[] args) {

		Point p1 = new Point(10, 20);
		Point p2 = new Point(1, 2);

		System.out.println("p1 =  " + p1.toString());
		System.out.println("p2 =  " + p2.toString());	
		System.out.println("Is p1 equals to p2 ? " + p1.isEqual(p2));
		System.out.println("The distance between p1 and p2 is " + p1.calculateDistance(p2));

	}

}
