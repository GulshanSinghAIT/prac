import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5 {

    public static String getMD5Hash(String input) throws NoSuchAlgorithmException {
        // Get MessageDigest instance for MD5
        MessageDigest md = MessageDigest.getInstance("MD5");

        // Update the digest with the input string bytes
        md.update(input.getBytes());

        // Perform the hash calculation
        byte[] digest = md.digest();

        // Convert byte array to hexadecimal format
        StringBuilder hexString = new StringBuilder();
        for (byte b : digest) {
            // Convert each byte to a 2-digit hexadecimal representation
            hexString.append(String.format("%02x", b));
        }

        // Return the hex string (MD5 hash)
        return hexString.toString();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        String input = "HelloWorld";  // Example input string
        String md5Hash = getMD5Hash(input);

        System.out.println("MD5 Hash of \"" + input + "\" is: " + md5Hash);
    }
}
