"use strict";
let saldo = 3000;
const elementoSaldo = document.querySelector('.saldo-valor .valor');
// const elementoDataAcesso = document.querySelector('.block-saldo time') as HTMLElement;
if (elementoSaldo != null) {
    elementoSaldo.textContent = saldo.toString();
}
// if(elementoDataAcesso != null){
//     const dataAcesso: Date = new Date();
//     elementoDataAcesso.textContent = formatarData(dataAcesso);
// }
