param(
    [int]$in = (Read-Host "program number")
)
$parent = "9999"
if ($in -gt 19999) {
    $parent = "29999"
}
elseif ($in -gt 9999) {
    $parent = "19999"
}
g++.exe -g "$parent\\$in.cpp" -o "$parent\\$in.exe"
if (Test-Path -Path "$parent\\$in.test" -PathType Leaf){
    Get-Content "$parent\\$in.test" | & "$parent\\$in.exe"
}
else{
    & "$parent\\$in.exe"
}