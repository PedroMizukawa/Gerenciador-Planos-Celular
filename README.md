# Gerenciador-Planos-Celular
A estrutura de dados utilizada é uma lista encadeada estática, implementada sobre um vetor de tamanho fixo (MAX = 10), onde os ponteiros são índices inteiros em vez de ponteiros reais — técnica comum em sistemas embarcados e ambientes com memória limitada.
# Funcionalidades
- 1	Cadastrar novo plano (número + créditos iniciais)
- 2	Cancelar plano (remover cliente)
- 3	Registrar gasto de internet (remover créditos)
- 4	Vender créditos (adicionar créditos)
- 0	Sair do sistema

**A lista é mantida ordenada por número de celular a cada inserção**.

# Conceitos aplicados
- Lista encadeada estática (vetor com ponteiros como índices)
- Inserção ordenada em lista encadeada
- Gerenciamento de nós disponíveis (lista de livres)
- KCL em estruturas de dados (busca, inserção e remoção)
