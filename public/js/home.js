$(document).ready(function () {
    //Kết nối tới server socket đang lắng nghe
  
    socket.on("severSendDataFromEspToClient", function (data) {
        console.log("đây là gói tin từ esp vể");
        console.log(data);

    })

})