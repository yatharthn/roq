set(TARGET_NAME "${PROJECT_NAME}-schema-fbs")

set(TARGET_DIR "${CMAKE_INSTALL_DATADIR}/roq/schema/fbs")

set(SOURCES
    api.fbs
    cancel_all_orders.fbs
    cancel_order.fbs
    connection_status.fbs
    create_order.fbs
    custom_metrics.fbs
    custom_metrics_update.fbs
    download_begin.fbs
    download_end.fbs
    encoding.fbs
    error.fbs
    execution_instruction.fbs
    fill.fbs
    funds_update.fbs
    gateway_settings.fbs
    gateway_status.fbs
    layer.fbs
    market_by_order_update.fbs
    market_by_price_update.fbs
    market_status.fbs
    mbo_update.fbs
    mbp_update.fbs
    measurement.fbs
    modify_order.fbs
    option_type.fbs
    order_ack.fbs
    order_status.fbs
    order_type.fbs
    order_update_action.fbs
    order_update.fbs
    origin.fbs
    position_effect.fbs
    position_update.fbs
    priority.fbs
    protocol.fbs
    rate_limit_trigger.fbs
    rate_limit_type.fbs
    reference_data.fbs
    request_status.fbs
    request_type.fbs
    security_type.fbs
    side.fbs
    statistics.fbs
    statistics_type.fbs
    statistics_update.fbs
    stream_status.fbs
    support_type.fbs
    time_in_force.fbs
    top_of_book.fbs
    trade.fbs
    trade_summary.fbs
    trade_update.fbs
    trading_status.fbs
    transport.fbs
    update_action.fbs
    update_type.fbs)

# install

install(FILES ${SOURCES} DESTINATION "${TARGET_DIR}")
