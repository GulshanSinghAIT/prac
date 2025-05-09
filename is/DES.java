import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class DES {
    public static void main(String[] args) throws Exception {
        String plainText = "HelloWorld";

        // Generate DES key
        KeyGenerator keyGen = KeyGenerator.getInstance("DES");
        SecretKey secretKey = keyGen.generateKey();

        // Create Cipher instance and initialize it
        Cipher desCipher = Cipher.getInstance("DES");

        // Encryption
        desCipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = desCipher.doFinal(plainText.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
        System.out.println("Encrypted Text (DES): " + encryptedText);

        // Decryption
        desCipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = desCipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println("Decrypted Text (DES): " + decryptedText);
    }
}