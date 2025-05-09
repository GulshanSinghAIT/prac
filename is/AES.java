import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class AES {
    public static void main(String[] args) throws Exception {
        String plainText = "HelloWorld123";

        // Generate AES key
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128); // 128-bit AES
        SecretKey secretKey = keyGen.generateKey();

        // Create Cipher instance and initialize it
        Cipher aesCipher = Cipher.getInstance("AES");

        // Encryption
        aesCipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = aesCipher.doFinal(plainText.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
        System.out.println("Encrypted Text (AES): " + encryptedText);

        // Decryption
        aesCipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = aesCipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println("Decrypted Text (AES): " + decryptedText);
    }
}