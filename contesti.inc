<?php
function contesto($parola, $FileNameXml){
    shell_exec("curl http://web-ngram.research.microsoft.com/similarity/SimRest.svc/?w=" . $parola . " > scraping.html");
    $a = file_get_contents("scraping.html");
    $valori = explode(" ", $a);
    $valori[0] = substr($valori[0], 3);


        file_put_contents($FileNameXml,"\t<contesti>\n", FILE_APPEND);
        if(count($valori) > 1){
            foreach ($valori as $v) {
                file_put_contents($FileNameXml,"\t\t<contesto>\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t" . $v . "\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</contesto>\n" , FILE_APPEND);
            }
        }
        file_put_contents($FileNameXml,"\t</contesti>\n" , FILE_APPEND);
}
?>