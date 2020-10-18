# Testes e implementação da função 'payment'
Para rodar os testes use o comando `make`

## Classes de Equivalência
| Variável de entrada | Classes de equivalência válidas | Classes de equivalência inválidas |
|---------------------|---------------------------------|-----------------------------------|
| Valor (v) do pagamento | 0,01 ≤ v ≤ 99.999,00 | v < 0,01 \|\| v > 99.999,00 |
| Status (s) do Assinante | s faz parte da lista de strings aceitas | s não faz parte da lista de strings aceitas |

## Casos de Teste

| Valor (v) | Status (s) do Assinante | Saída Esperada |
|-|-|-|
| 0.01 | "estudante" | 0 |
| 99999.00 | "vip" | 0 |
| 1000.52 | "aposentado" | 0 |
| 00.00 | "regular" | 1 |
| 99999.01 | "regular" | 1 |
| 5000.63 | "regular" | 2 |
