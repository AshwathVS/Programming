import java.util.*;

public class red_green_apples {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		Integer red[] = new Integer[A];
		Integer green[] = new Integer[B];
		Integer clear[] = new Integer[C];
		
		for(int i = 0; i < A; i++){
			red[i] = sc.nextInt();
		}
		for(int i = 0; i < B; i++){
			green[i] = sc.nextInt();
		}
		for(int i = 0; i < C; i++){
			clear[i] = sc.nextInt();
		}
		
		Arrays.sort(red, Collections.reverseOrder());
		Arrays.sort(green, Collections.reverseOrder());

		Integer apple[] = new Integer[X + Y + C];
		for(int i = 0; i < X; i++)apple[i] = red[i];
		for(int i = 0; i < Y; i++)apple[i + X] = green[i];
		for(int i = 0; i < C; i++)apple[i + X + Y] = clear[i];
		Arrays.sort(apple, Collections.reverseOrder());
		
		long sum = 0;
		for(int i = 0; i < X + Y; i++){
			sum += apple[i];
		}
		System.out.println(sum);
	}
}
