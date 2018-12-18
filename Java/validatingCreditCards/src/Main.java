import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        //System.out.println("Hello World!");
        System.out.print("Enter a credit card number as a long integer: ");
        Scanner input = new Scanner(System.in);
        long cardNumber = input.nextLong();
        CheckValidation check = new CheckValidation(cardNumber);
        if(check.validating()) {
            System.out.println(cardNumber + " is valid");
        }
        else {
            System.out.println(cardNumber + " is invalid");
        }
    }
}
class CheckValidation {
    long cardNumber;
    CheckValidation(long number) {
        cardNumber = number;
    }
    boolean validating() {
        //System.out.println(cardNumber/10);
        int[] cardNumberArray = new int[16];
        for(int i=0;i<16;i++) cardNumberArray[i] = -1;
        int cardNumberLength = 1;
        long tmpCardNumber = cardNumber;
        while(tmpCardNumber / 10 != 0){
            tmpCardNumber /= 10;
            cardNumberLength++;
        }
        //System.out.println(cardNumberLength);
        tmpCardNumber = cardNumber;
        for(int i=0;i<cardNumberLength;i++) {
            //System.out.println("" + i + tmp % 10);
            cardNumberArray[i] = (int)(tmpCardNumber % 10);
            tmpCardNumber /= 10;
        }
        //for(int i=0;i<16;i++) System.out.println(cardNumberArray[i]);
        // Steps
        int sum1 = 0,sum2 = 0;
        for(int i=0;i<16 && cardNumberArray[i]!=-1;i++) {
            // Step 1
            if(i % 2 == 1) {
                if(2 * cardNumberArray[i] < 10) {
                    sum1 += 2 * cardNumberArray[i];
                    //System.out.println(2 * cardNumberArray[i]);
                }
                else {
                    int tmpSum = (2*cardNumberArray[i])/10 + (2*cardNumberArray[i])%10;
                    sum1 += tmpSum;
                    //System.out.println(tmpSum);
                }
            }
            //Step 2
            else {
                sum2 += cardNumberArray[i];
            }
        }
        //System.out.println(sum1);
        //System.out.println(sum2);
        if((sum1 + sum2) % 10 == 0) return true;
        else return false;
    }
}