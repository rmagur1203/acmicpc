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

if (Test-Path -Path "$parent\\$in.c" -PathType Leaf){
    Write-Output "gcc.exe -g $parent\\$in.c -o $parent\\$in.exe"
    gcc.exe -g "$parent\\$in.c" -o "$parent\\$in.exe"
}
if (Test-Path -Path "$parent\\$in.cpp" -PathType Leaf){
    Write-Output "g++.exe -g $parent\\$in.cpp -o $parent\\$in.exe"
    g++.exe -g "$parent\\$in.cpp" -o "$parent\\$in.exe"
}

if (Test-Path -Path "$parent\\$in.test" -PathType Leaf){
    Write-Output "Get-Content $parent\\$in.test | & $parent\\$in.exe"
    Get-Content "$parent\\$in.test" | Write-Output
    Get-Content "$parent\\$in.test" | & "$parent\\$in.exe"
}
else{
    & "$parent\\$in.exe"
}