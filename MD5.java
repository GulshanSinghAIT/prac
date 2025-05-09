import java.security.MessageDigest;
import java.math.BigInteger;
import java.util.Scanner;

public class MD5 {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the text to hash: ");
            String input = scanner.nextLine();

            // Create MessageDigest instance for MD5
            MessageDigest md = MessageDigest.getInstance("MD5");

            // Compute the digest (returns byte array)
            byte[] messageDigest = md.digest(input.getBytes());

            // Convert byte array into signum representation (positive number)
            BigInteger no = new BigInteger(1, messageDigest);

            // Convert message digest into hex value
            String hashText = no.toString(16);

            // Pad with leading zeros to make it 32 characters
            while (hashText.length() < 32) {
                hashText = "0" + hashText;
            }

            System.out.println("MD5 Digest: " + hashText);

        } catch (Exception e) {
            System.out.println("Error occurred: " + e);
        }
    }
}
