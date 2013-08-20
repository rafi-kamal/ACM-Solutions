import java.util.ArrayList;
import java.util.Scanner;


public class Main {
    
    static ArrayList<String> history;
    static Scanner input = new Scanner(System.in);
    static int currentAddress;
    static int totalAddress;
    
    public static void main(String[] args) {
        int cases = input.nextInt();
        
        for(int i = 0; i < cases; i++)
            f(i + 1);
    }
    
    private static void f(int i) {        
        history = new ArrayList<String>(100);
        history.add("http://www.lightoj.com/");
        currentAddress = 0;
        totalAddress = 1;
        System.out.println("Case " + i + ":");
        
        while(true) {
            String command = input.next();

            if(command.equals("VISIT")) {
                String address = input.next(); 
                currentAddress++;
                history.add(currentAddress, address); 
                totalAddress = currentAddress + 1;

                System.out.println(address);
            }

            else if(command.equals("BACK")) {
                if(currentAddress == 0)
                    System.out.println("Ignored");
                else {
                    currentAddress--;
                    System.out.println(history.get(currentAddress));
                }
            }

            else if(command.equals("FORWARD")) {
                if(currentAddress == totalAddress - 1)
                    System.out.println("Ignored");
                else {
                    currentAddress++;
                    System.out.println(history.get(currentAddress));                
                }
            }
            
            else if(command.equals("QUIT"))
                return;
        }
    }
}
