public abstract class TokenFactory {

    public TokenFactory() {
    }

    public abstract Token createToken(int xLower, int xUpper, int yLower, int yUpper);
}