import jq from 'jq';

console.log(jq); // 检查 jq 是否正确加载

const $ = jq;

$(document).ready(function() {
  console.log('Document is ready'); // 检查是否进入 ready 事件
  $(".btn").hide();
});
