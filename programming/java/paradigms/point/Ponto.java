package coordenada;

public class Ponto {

	private int x;
	private int y;
	
	public Ponto(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
	
	public boolean isEquals (Ponto ponto) {
		return this.x == ponto.getX() && this.y == ponto.getY();
	}
	
	public double distance(Ponto ponto) {
		if(this.isEquals(ponto))
			return 0.0;
		return Math.sqrt(Math.pow((ponto.getX() - this.x), 2) + (Math.pow((ponto.getY() - this.y), 2)));
	}
}
