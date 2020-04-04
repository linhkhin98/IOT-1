$(document).ready(function(){
  socket.emit("clientSend","{client:OK}");
  let json={
    LED1:0,
    LED2:0,
}
    $(".fa-lightbulb-o.bong1").unbind("click").on("click",function(){
        var trangthai = $(this).data('ttb1');
      if(trangthai==0){
        $(this).addClass("active");    
        $(this).data('ttb1',1);
        json.LED1=1;
        socket.emit("LED1", json);
        

      }
      else if(trangthai==1){
        $(this).removeClass("active");
        $(this).data('ttb1',0);
        json.LED1=0;
        socket.emit("LED1", json);


      }
    })
    $(".fa-lightbulb-o.bong2").unbind("click").on("click",function(){
      var trangthai = $(this).data('ttb1');
      
     

    if(trangthai==0){
      $(this).addClass("active");    
      $(this).data('ttb1',1);
      json.LED2=1;
      socket.emit("LED2", json);

    }
    else if(trangthai==1){
      $(this).removeClass("active");
      $(this).data('ttb1',0);
      json.LED2=0;
      socket.emit("LED2", json);


    }
  })
})