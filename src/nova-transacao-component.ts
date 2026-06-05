const elementoFormulario = document.querySelector('.block-nova-transacao form') as HTMLFormElement;
elementoFormulario.addEventListener("submit", function(evt){
    evt.preventDefault();
    if(!elementoFormulario.checkValidity()){
        alert("preencha todos os campos!");
        return;
    }

    const inputTipoTransacao = elementoFormulario.querySelector('#tipoTransacao') as HTMLInputElement;
    const inputValor = elementoFormulario.querySelector('#valor') as HTMLInputElement;
    const inputData = elementoFormulario.querySelector('#data') as HTMLInputElement;

    let tipoTransacao = inputTipoTransacao.value as TipoTransacao;
    let valor = inputValor.valueAsNumber;
    let data = new Date(inputData.value);

    if (tipoTransacao == "Depósito"){
        saldo += valor;
    } else if (tipoTransacao == "Transferência" || tipoTransacao == "Pagamento de Boleto") {
        saldo -= valor;
    } else {
        alert("Tipo de Transação inválido!");
        return; 
    }
    elementoSaldo.textContent = saldo.toString();
    
    const novaTransacao: Transacao = {
        tipoTransacao: tipoTransacao,
        valor: valor,
        data: data
    }

    console.log(novaTransacao);
    elementoFormulario.reset();
});