<?php
    include('sinonimi_contrari.inc');
    include('rime.inc');
    include('contesti.inc');
    include('dialetti.inc');
    include('traduci.inc');
    include('wordnet.inc');
    include('wiki.inc');
    include('modi.inc');

    $FileNameXml = 'file.xml';
    $FileNameXsl = 'form.xsl';    
    
    $parola = $_POST['parola'];
    crea_XML($parola, $FileNameXml, $_POST['checkbox'], $_POST['lingua']);
    $xslDoc = new DOMDocument();
    $xslDoc->load($FileNameXsl);
    $xmlDoc = new DOMDocument();
    $xmlDoc->load($FileNameXml);
    $proc = new XSLTProcessor();
    $proc->importStylesheet($xslDoc);
    echo $proc->transformToXML($xmlDoc);
    
    
    function crea_XML($parola, $FileNameXml, $checked, $lingua){
        $string = '';
        foreach ($checked as $key => $value) {
            extract(array($value => $value));
        }
        
        extract(array($lingua => $lingua));

        //bisogna creare il file "file.xml" e dare i permessi con chmod 0777 file.xml a mano se no ci sono problemi di permessi
        file_put_contents($FileNameXml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
        file_put_contents($FileNameXml, "<?xml-stylesheet type=\"text/xsl\" href=\"form.xsl\"?>\n", FILE_APPEND);
        file_put_contents($FileNameXml,"<dati parola=\"".$parola."\">\n", FILE_APPEND);
        
        if(isset($italiano)){
            if(isset($sinonimi) || isset($contrari))
                sinonimi_contrari($parola, $FileNameXml, @check($sinonimi, $contrari));
            if(isset($rime))
                rime($parola, $FileNameXml);
            if(isset($contesti))
                contesto($parola, $FileNameXml);
            if(isset($dialetti))
                dialetti($parola, $FileNameXml);
            if(isset($traduzioni))
                traduci($parola, "it", "en", $FileNameXml);
            if(isset($modi))
                modi_di_dire($parola, $FileNameXml);
            if(isset($wikipedia))
            wiki($parola, "it", $FileNameXml);
        }
        else{
            if(isset($overviews))
                wordnet_overview($parola, $FileNameXml);
            if(isset($synonyms))
                wordnet_synsn($parola, $FileNameXml);
            if(isset($traduzioni))
                traduci($parola, "en", "it", $FileNameXml);
            if(isset($wikipedia))
            wiki($parola, "en", $FileNameXml);
        }
        file_put_contents($FileNameXml,"</dati>" , FILE_APPEND);
        
    }
?>