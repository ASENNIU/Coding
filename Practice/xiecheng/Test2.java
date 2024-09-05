import java.util.Scanner;

public class Test2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); 
        String s = scanner.next(); 
        

        int count = 0;
        
       
        for (int start = 0; start < n; start++) {
            int flips = 0; 
            for (int length = 1; start + length <= n; length += 2) { // 

                int end = start + length - 1;
                

                for (int i = start; i <= end; i++) {
                    if (s.charAt(i) == '1') {
                        flips++; 
                    }
                }
                
       
                if (flips % 2 == 1) {
                    count++;
                }
            }
        }
        

        System.out.println(count);
    }
}
