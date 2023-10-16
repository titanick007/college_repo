class Music{
    public void play(){
        System.out.println("Song is playing");
    }
    public void pause(){
        System.out.println("Song has been paused");
    }
    public void next_song(){
        System.out.println("Playing next song");
    }
}
class Panasonic extends Music{}
class Sony extends Music{
    @Override
    public void play(){
        System.out.println("random song playing");
    }
}
public class Musicplayer{
    public static void main(String[] args){
        Panasonic musicplayer1=new Panasonic();
        Sony musicplayer2=new Sony();
        //play() for Panasonic object
        musicplayer1.play();
        //play() for Sony object
        musicplayer2.play();
    }
}
