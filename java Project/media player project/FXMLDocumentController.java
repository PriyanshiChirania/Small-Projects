
package newtry;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.beans.binding.Bindings;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import javafx.stage.FileChooser;
import javafx.beans.property.DoubleProperty;

import javafx.scene.control.Slider;
import javafx.util.Duration;



public class FXMLDocumentController implements Initializable {
 
    private MediaPlayer mediaPlayer;
     @FXML
    Duration duration1;
    
    @FXML
    private MediaView mediaView;
    
       
    @FXML
    private Slider slider;
    
    @FXML
    private Slider seeSlider;
    
    
     
     private String filePath;
    @FXML
    private void mvclick(ActionEvent event) {}
    @FXML
    private void handleButtonAction(ActionEvent event) {
       
       FileChooser fileChooser = new FileChooser();
       FileChooser.ExtensionFilter filter = new FileChooser.ExtensionFilter("Select a file (*.mp4)", "*.mp4");
       //FileChooser.ExtensionFilter filter1 = new FileChooser.ExtensionFilter("Select a file (*.mp3)", "*.mp3");
            fileChooser.getExtensionFilters().add(filter);
            
            File file = fileChooser.showOpenDialog(null);
            filePath = file.toURI().toString();
            
            if(filePath!=null){
                Media media = new Media(filePath);
                mediaPlayer = new MediaPlayer(media);
                mediaView.setMediaPlayer(mediaPlayer);
                
                
                
                DoubleProperty width= mediaView.fitWidthProperty();
                DoubleProperty height=mediaView.fitHeightProperty();
                
                width.bind(Bindings.selectDouble(mediaView.sceneProperty(), "width"));
                height.bind(Bindings.selectDouble(mediaView.sceneProperty(), "height"));
            
                
                slider.setValue(mediaPlayer.getVolume()*100);
                slider.valueProperty().addListener(new InvalidationListener() {
                    @Override
                    public void invalidated(Observable observable) {
                                     mediaPlayer.setVolume(slider.getValue()/100);

                    }
                });
                
 //seek the slider by pressing at a position            
       InvalidationListener sliderChangeListener = o-> {
             Duration seekTo = Duration.seconds(seeSlider.getValue());
                mediaPlayer.seek(seekTo);
           };

        seeSlider.valueProperty().addListener(sliderChangeListener);

// Link the player's time to the seeslider
        mediaPlayer.currentTimeProperty().addListener(l-> {
    
 //if the user slides the slider instead of just clicking a position on it.
    seeSlider.valueProperty().removeListener(sliderChangeListener);
         Duration currentTime = mediaPlayer.getCurrentTime();
         int value = (int) currentTime.toSeconds();
         seeSlider.setValue(value);    
        
  // Re-add the slider listener
        seeSlider.valueProperty().addListener(sliderChangeListener);
});
                  
                //to stop when the end of video is encountered
                seeSlider.maxProperty().bind(Bindings.createDoubleBinding(
                () -> mediaPlayer.getTotalDuration().toSeconds(),
                mediaPlayer.totalDurationProperty()));
            
         

                mediaPlayer.play();
            }
    }
    
    @FXML
    private void pauseVideo(ActionEvent event){
        mediaPlayer.pause();
    }
    @FXML
    private void playVideo(ActionEvent event){
        mediaPlayer.play();
        mediaPlayer.setRate(1);
        duration1 = mediaPlayer.getMedia().getDuration();
    }
    @FXML
    private void stopVideo(ActionEvent event){
        mediaPlayer.stop();
    }
    @FXML
    private void fastVideo(ActionEvent event){
        mediaPlayer.setRate(1.5);
    }
    @FXML
    private void fasterVideo(ActionEvent event){
         mediaPlayer.setRate(2);
    }
    @FXML
    private void slowVideo(ActionEvent event){
         mediaPlayer.setRate(0.75);
    }
    @FXML
    private void slowerVideo(ActionEvent event){
         mediaPlayer.setRate(0.5);
    }
    @FXML
    private void exitVideo(ActionEvent event){
        System.exit(0);
    }
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
}
    