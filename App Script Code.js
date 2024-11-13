function doPost(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  var data = JSON.parse(e.postData.contents);
  
  // Append a new row with Timestamp and MQ2 sensor value
  sheet.appendRow([new Date(), data.mq2_value]);
  return ContentService.createTextOutput("Data received successfully");
}
