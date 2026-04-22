import java.util.Scanner;



public class Main {



	public static void main(String[] args) {



		Scanner scan = new Scanner(System.in);

		int num = scan.nextInt();

		int[] result = new int[num];



		for (int i = 0; i < num; i++) {

			int x = scan.nextInt();

			int y = scan.nextInt();

			int dist = y - x;

		

			int n = (int)Math.ceil(Math.sqrt(dist));

			int maxDist =(int)Math.pow(Math.ceil(Math.sqrt(dist)),2);

			int maxNum = n*2 -1 ;

			int numberOfTimes = maxNum ;

			

			if(dist <= maxDist-n) {

				numberOfTimes = maxNum-1;

			}

			result[i] = numberOfTimes;

		}

		

		for(int res : result) {

			System.out.println(res);

		}

		

		scan.close();

	}



}

