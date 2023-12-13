/**
 * Add globals here
 */

/**
 * Initialize functions here.
 */
$(document).ready(function(){

    getDevicesStatusValues();

    $("#lamp_1_toggle, #lamp_2_toggle, #fan_toggle").on("click", function () 
    {
        var deviceIndex = $(this).data("device-index");
        toggleStatus(deviceIndex);
    });

    startDHTSensorInterval();
});

/**
 * Gets DHT sensor temperature and humidity values for display on the web page.
 */
function getDHTSensorValues()
{
	$.getJSON('/dhtSensor.json', function(data) {
		$("#temperature_reading").text(data["temp"]);
		$("#humidity_reading").text(data["hum"]);
	});
}

/**
 * Sets the interval for getting the updated DHT22 sensor values.
 */
function startDHTSensorInterval()
{
	setInterval(getDHTSensorValues, 10000);
}

/**
 * Toggles devices status by web page buttons 
 * @param deviceIndex 
 *      device 0 - Lamp 1
 *      device 1 - Lamp 2
 *      device 2 - Fan
 */
function toggleStatus(deviceIndex) 
{
    deviceSelected = "";

    if (deviceIndex == 0)
    {
        deviceSelected = "lamp1";
    }
    if (deviceIndex == 1)
    {
        deviceSelected = "lamp2";
    }
    if (deviceIndex == 2)
    {
        deviceSelected = "fan";
    }

    console.log(deviceSelected);

    // Http Request
    $.ajax({
        url: '/devicesControl',
        type: 'POST',
        contentType: 'application/x-www-form-urlencoded',
        data: 'deviceSelected=' + encodeURIComponent(deviceSelected),
        success: function (response)
        {
            console.log(response);
            setTimeout(function(){
                getDevicesStatusValues();
            }, 500);
        },
        error: function (XMLHttpRequest, status, error)
        {
            console.error('Erro na requisição:', status, error);
        }
    });  
}

/**
 * Gets devices status values for display on the web page.
 */
function getDevicesStatusValues()
{
     
    $.ajax({
        url: '/devicesStatus.json',
        type: 'POST',
        dataType: 'json',
        success: function (data)
        {
            $("#lamp_1_toggle").val(data["device-1"]);
            $("#lamp_2_toggle").val(data["device-2"]);
            $("#fan_toggle").val(data["device-3"]);
        },
        error: function (XMLHttpRequest, status, error)
        {
            console.error('Erro na requisição:', status, error);
        }
    });
}