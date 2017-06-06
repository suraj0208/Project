import java.io.BufferedReader;
import java.io.InputStreamReader;

class TCPDumpInterface{
	
	String source = "192.168.0.120";
	
	public void run(){		
		(new Thread(){
			@Override
			public void run() {
				
				try {
					Process pr = Runtime.getRuntime().exec("tcpdump -i wlan0");
				
					BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(pr.getInputStream()));
					
					String s;
					
					while((s=bufferedReader.readLine())!=null){
						
						if(s.contains(source)){
							System.out.println(s.split(" ")[0]);
						}
						
					}
								
				} catch (Exception e) {
					e.printStackTrace();
				}
				
				
			}
			
		}).start();
	}
}

public class Recver {
	
	public static void main(String[] args) {
			(new TCPDumpInterface()).run();

	}
}
