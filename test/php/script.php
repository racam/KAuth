<?php

if(isset($_POST['signature'])){
	
	$signature = base64_decode($_POST['signature']);
	$data = $_POST['data'];
	
	$key = <<<EOF
-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDufjnCGHQqVtEd7740ObAKG8de
I29E7/lTGkn1VIMx4HasES/1PccW8kbnfif7ujo+YDFfFWdvjmieGNa3Q5GoYR6s
qocSsDmGGzy+TkWpW7Aq6g8gKTEPcMYVHyQG5CmBXuQKotp6SAD0ost2zG52aYoG
8f8u5Ph97OE3uxeVDwIDAQAB
-----END PUBLIC KEY-----
EOF;

	if(openssl_verify($data, $signature, $key)){
		$test = "OK verify";
	}else{
		$test = "Not OK :(";
	}
}else{
	$test = "Generer une signature";
	$data = str_shuffle("Ceciestunphrasetest");
}


?>

<html>
<head>
	<title>Test authentification K-Auth</title>
</head>
<body>
<h2>Test</h2>
<?php echo $test; ?>

<?php if(isset($data)): ?>
	<br><br><br>

<form method="POST">
	<input type="hidden" name="data" value="<?php echo $data; ?>">
	<p>a signer :<br><?php echo $data; ?><p>
	<label for="signature">Signature</label><input type="text" name="signature" id="signature">
</form>
<?php endif; ?>

</body>
</html>
